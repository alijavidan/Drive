CXXFLAGS := -std=c++11
a.out: main.o Classes.o functions.o
	g++ main.o Classes.o functions.o

main.o: main.cpp Classes.hpp functions.hpp
	g++ -c main.cpp

Classes.o: Classes.cpp Classes.hpp
	g++ -c Classes.cpp

functions.o: functions.cpp functions.hpp Classes.hpp exceptions.hpp
	g++ -c functions.cpp
clean:
	rm *.o a.out   
