
clean:
	rm *.*~ *.out makefile~

cleanwin:
	rm *.*~ *.exe a.exe.stackdump makefile~
	rm ./CodeForces/*.*~ ./CodeForces/*.exe ./CodeForces/a.exe.stackdump ./CodeForces/makefile~

compile:
	g++ -std=c++14 057_Insert_Interval.cpp
	./a.out

compwin:
	g++ -std=c++17 064_Minimum_Path_Sum.cpp
	./a.exe


