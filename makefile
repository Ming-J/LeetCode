
clean:
	rm *.*~ *.out makefile~

cleanwin:
	rm *.*~ *.exe a.exe.stackdump makefile~

compile:
	g++ -std=c++14 397_Integer_Replacement.cpp
	./a.out

compwin:
	g++ -std=c++17 397_Integer_Replacement.cpp
	./a.exe


