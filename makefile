
clean:
	rm *.*~ *.out makefile~

cleanwin:
	rm *.*~ *.exe a.exe.stackdump makefile~
	rm ./CodeForces/*.*~ ./CodeForces/*.exe ./CodeForces/a.exe.stackdump ./CodeForces/makefile~

compile:
	g++ -std=c++17 1003_Check_Word_Valid_Substitutions.cpp
	./a.out

compwin:
	g++ -std=c++17 886_Possible_Bipartition.cpp
	./a.exe


