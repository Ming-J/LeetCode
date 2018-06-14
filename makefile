
clean:
	rm *.*~ *.out makefile~

cleanwin:
	rm *.*~ *.exe a.exe.stackdump makefile~
	rm ./CodeForces/*.*~ ./CodeForces/*.exe ./CodeForces/a.exe.stackdump ./CodeForces/makefile~

compile:
	g++ -std=c++14 637_Average_Of_Levels_In_Binary_Tree.cpp
	./a.out

compwin:
	g++ -std=c++17 Connect_4.cpp
	./a.exe


