
clean:
	rm *.*~ *.out makefile~

cleanwin:
	rm *.*~ *.exe a.exe.stackdump makefile~
	rm ./CodeForces/*.*~ ./CodeForces/*.exe ./CodeForces/a.exe.stackdump ./CodeForces/makefile~

compile:
	g++ -std=c++14 037_Sudoku_Solver.cpp
	./a.out

compwin:
	g++ -std=c++17 037_Sudoku_Solver.cpp
	./a.exe


