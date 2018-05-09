
clean:
	rm *.*~ *.out makefile~

cleanwin:
	rm *.*~ *.exe a.exe.stackdump makefile~

compile:
	g++ -std=c++14 802_Find_Eventual_Safe_States.cpp
	./a.out

compwin:
	g++ -std=c++17 128v2_Longest_Consecutive_Sequence.cpp
	./a.exe


