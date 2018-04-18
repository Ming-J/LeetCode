
clean:
	rm *.*~ *.out makefile~

cleanwin:
	rm *.*~ *.exe a.exe.stackdump makefile~

compile:
	g++ -std=c++14 787_Cheapest_Flights_Within_K_Stops.cpp
	./a.out

compwin:
	g++ -std=c++17 787_Cheapest_Flights_Within_K_Stops.cpp
	./a.exe


