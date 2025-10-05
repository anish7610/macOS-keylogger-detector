CXX = g++
CXXFLAGS = -std=c++17
LDFLAGS = -L/usr/lib -lsqlite3 

waf: $(wildcard *.cpp)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f keylogger_detector 
