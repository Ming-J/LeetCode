clean:
	rm *.*~ *.out makefile~

cleanwin:
	rm *.*~ *.exe a.exe.stackdump makefile~

compile:
	g++ -std=c++11 688_Knight_Probability_In_Chessboard.cpp
	./a.out
