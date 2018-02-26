
clean:
	rm *.*~ *.out makefile~

cleanwin:
	rm *.*~ *.exe a.exe.stackdump makefile~

compile:
	g++ -std=c++14 743_NetworkDelay.cpp
	./a.out

compwin:
	g++ -std=c++17 743_NetworkDelay.cpp
	./a.exe


