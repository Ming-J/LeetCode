
clean:
	rm *.*~ *.out makefile~

cleanwin:
	rm *.*~ *.exe a.exe.stackdump makefile~
	rm ./CodeForces/*.*~ ./CodeForces/*.exe ./CodeForces/a.exe.stackdump ./CodeForces/makefile~

compile:
	g++ -std=c++17 953_Verifying_An_Alien_Dictionary.cpp
	./a.out

compwin:
	g++ -std=c++17 886_Possible_Bipartition.cpp
	./a.exe


