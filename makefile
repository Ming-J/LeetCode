
clean:
	rm *.*~ *.out makefile~

cleanwin:
	rm *.*~ *.exe a.exe.stackdump makefile~
	rm ./CodeForces/*.*~ ./CodeForces/*.exe ./CodeForces/a.exe.stackdump ./CodeForces/makefile~

compile:
	g++ -std=c++14 133_Clone_Graph.cpp
	./a.out

compwin:
	g++ -std=c++17 Connect_4.cpp
	./a.exe


