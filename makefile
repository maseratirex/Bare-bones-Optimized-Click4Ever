CXX=g++
FRMWRKS=-framework ApplicationServices

autoclicker: autoclicker.o
	$(CXX) autoclicker.o $(FRMWRKS) -o autoclicker

autoclicker.o: autoclicker.cpp
	$(CXX) -c autoclicker.cpp

clean:
	rm *.o autoclicker