
clean:
	rm *.*~ *.out makefile~

cleanwin:
	rm *.*~ *.exe a.exe.stackdump makefile~
	rm ./CodeForces/*.*~ ./CodeForces/*.exe ./CodeForces/a.exe.stackdump ./CodeForces/makefile~

compile:
	g++ -std=c++17 GS720_Longest_Word_In_Dictionary.cpp
	./a.out

compwin:
	g++ -std=c++17 GS146_LRU_Cache.cpp
	./a.exe


