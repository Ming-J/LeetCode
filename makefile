
clean:
	rm *.*~ *.out makefile~

cleanwin:
	rm *.*~ *.exe a.exe.stackdump makefile~

compile:
	g++ -std=c++14 connect4GridString.cpp
	./a.out

compwin:
	g++ -std=c++17 Connect_4.cpp
	./a.exe


