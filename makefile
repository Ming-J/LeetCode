
clean:
	rm *.*~ *.out makefile~

cleanwin:
	rm *.*~ *.exe a.exe.stackdump makefile~

compile:
	g++ -std=c++14 802_Find_Eventual_Safe_States.cpp
	./a.out

compwin:
	g++ -std=c++17 804_Unique_Morse.cpp
	./a.exe


