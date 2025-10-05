### Running the Program

- make keylogger_detector
- ./keylogger_detector

<pre>
MacBook-Air-2:macOS-keylogger-detector anish$ ./keylogger_detector 
Detected Apps with Accessibility Permissions:
-------------------------------------------------
App: /System/Library/Frameworks/CoreServices.framework/Versions/A/Frameworks/AE.framework/Versions/A/Support/AEServer auth value: 1 ⚠️ [POTENTIAL KEYLOGGER]
App: com.appium.AppiumForMac auth value: 1 ⚠️ [POTENTIAL KEYLOGGER]
App: com.apple.dt.Xcode-Helper auth value: 1 ⚠️ [POTENTIAL KEYLOGGER]
App: com.apple.finder auth value: 1 ✅ [Trusted]
App: com.electron.onvue auth value: 1 ⚠️ [POTENTIAL KEYLOGGER]
App: com.pfiddlesoft.uibrowser auth value: 1 ⚠️ [POTENTIAL KEYLOGGER]
App: io.appium.desktop auth value: 1 ⚠️ [POTENTIAL KEYLOGGER]
App: org.pqrs.Karabiner-Elements.Settings auth value: 1 ✅ [Trusted]
</pre>


### List Approved Apps that require Accessibility Permissions

<pre>
MacBook-Air-2:macOS-keylogger-detector anish$ sqlite3 /Library/Application\ Support/com.apple.TCC/TCC.db "SELECT * FROM access WHERE service='kTCCServiceAccessibility' and auth_value=1;"
kTCCServiceAccessibility|/System/Library/Frameworks/CoreServices.framework/Versions/A/Frameworks/AE.framework/Versions/A/Support/AEServer|1|1|4|1|??
                                                                                                                                                    ||0|UNUSED||0|1697226582
kTCCServiceAccessibility|com.appium.AppiumForMac|0|1|4|1|??
                                                           ||0|UNUSED||0|1739019361
kTCCServiceAccessibility|com.apple.dt.Xcode-Helper|0|1|4|1|??
                                                             ||0|UNUSED||0|1652577964
kTCCServiceAccessibility|com.apple.finder|0|1|4|1|??
                                                    ||0|UNUSED||0|1739021049
kTCCServiceAccessibility|com.electron.onvue|0|1|4|1|??
                                                      ||0|UNUSED||0|1699655639
kTCCServiceAccessibility|com.pfiddlesoft.uibrowser|0|1|4|1|??
                                                             ||0|UNUSED||0|1652922553
kTCCServiceAccessibility|io.appium.desktop|0|1|4|1|??
                                                     ||0|UNUSED||0|1739019359
kTCCServiceAccessibility|org.pqrs.Karabiner-Elements.Settings|0|1|4|1|??
                                                                        ||0|UNUSED||0|1739021598
</pre>
