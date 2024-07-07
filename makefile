CXX=g++
FRMWRKS=-framework Carbon

# autoclicker: autoclicker.o
# 	$(CXX) autoclicker.o $(FRMWRKS) -o autoclicker

# autoclicker.o: autoclicker.cpp
# 	$(CXX) -c autoclicker.cpp

keylogger: keylogger.o
	$(CXX) keylogger.o $(FRMWRKS) -o keylogger

keylogger.o: keylogger.cpp
	$(CXX) -c keylogger.cpp

clean:
	rm *.o autoclicker keylogger