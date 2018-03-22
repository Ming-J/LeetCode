
clean:
	rm *.*~ *.out makefile~

cleanwin:
	rm *.*~ *.exe a.exe.stackdump makefile~

compile:
	g++ -std=c++14 397_Integer_Replacement.cpp
	./a.out

compwin:
	g++ -std=c++17 451_sort_Characters_By_Frequency.cpp
	./a.exe


