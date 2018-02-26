
clean:
	rm *.*~ *.out makefile~

cleanwin:
	rm *.*~ *.exe a.exe.stackdump makefile~

compile:
	g++ -std=c++14 743_NetworkDelay.cpp
	./a.out

compwin:
	g++ -std=c++14 84_Largest_Rectangle_In_Histogram.cpp
	./a.exe


