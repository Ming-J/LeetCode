
clean:
	rm *.*~ *.out makefile~

cleanwin:
	rm *.*~ *.exe a.exe.stackdump makefile~

compile:
	g++ -std=c++14 659_Split_Array_Into_Consective_Subsequences.cpp
	./a.out

compwin:
	g++ -std=c++17 787_Cheapest_Flights_Within_K_Stops.cpp
	./a.exe


