
clean:
	rm *.*~ *.out makefile~

cleanwin:
	rm *.*~ *.exe a.exe.stackdump makefile~

compile:
	g++ -std=c++14 palantir.cpp
	./a.out

compwin:
	g++ -std=c++17 089_Gray_Code.cpp
	./a.exe


