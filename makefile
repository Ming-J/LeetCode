
clean:
	rm *.*~ *.out makefile~

cleanwin:
	rm *.*~ *.exe a.exe.stackdump makefile~
	rm ./CodeForces/*.*~ ./CodeForces/*.exe ./CodeForces/a.exe.stackdump ./CodeForces/makefile~

compile:
	g++ -std=c++14 076_Minimum_Window_Substring.cpp
	./a.out

compwin:
	g++ -std=c++17 071_Simplify_Path2.cpp
	./a.exe


