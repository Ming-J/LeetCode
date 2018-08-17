
clean:
	rm *.*~ *.out makefile~

cleanwin:
	rm *.*~ *.exe a.exe.stackdump makefile~
	rm ./CodeForces/*.*~ ./CodeForces/*.exe ./CodeForces/a.exe.stackdump ./CodeForces/makefile~

compile:
	g++ -std=c++14 012_Integer_To_Roman.cpp
	./a.out

compwin:
	g++ -std=c++17 030_Substring_With_Concatenation_Of_All_Words.cpp
	./a.exe


