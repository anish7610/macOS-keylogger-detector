#include <iostream>
#include <unordered_set>
#include <sqlite3.h>

// Whitelist of trusted apps
const std::unordered_set<std::string> trustedApps = {
    "com.apple.finder",
    "org.pqrs.Karabiner-Elements.Settings"
};

void checkAccessibilityApps() {
    sqlite3* db;
    sqlite3_stmt* stmt;
    const char* dbPath = "/Library/Application Support/com.apple.TCC/TCC.db";

    // Open the database
    if (sqlite3_open(dbPath, &db) != SQLITE_OK) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    // SQL query to fetch client (app) and auth_value (permission status)
    std::string query = "SELECT client, auth_value FROM access WHERE service='kTCCServiceAccessibility' and auth_value=1;";

    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Error preparing query: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return;
    }

    std::cout << "Detected Apps with Accessibility Permissions:\n";
    std::cout << "-------------------------------------------------\n";

    // Loop through each result
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        const char* client = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        int auth_value = sqlite3_column_int(stmt, 1);

        std::string appName = client ? client : "Unknown";

        // Print the app name and its auth_value
        std::cout << "App: " << appName << " auth value: " << auth_value;

        // Check if the app is trusted
        if (auth_value == 1) { // Only check trusted status for approved apps
            if (trustedApps.find(appName) != trustedApps.end()) {
                std::cout << " ✅ [Trusted]";
            } else {
                std::cout << " ⚠️ [POTENTIAL KEYLOGGER]";
            }
        }

        std::cout << std::endl;
    }

    // Clean up
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

int main() {
    checkAccessibilityApps();
    return 0;
}
