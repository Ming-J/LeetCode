
clean:
	rm *.*~ *.out makefile~

cleanwin:
	rm *.*~ *.exe a.exe.stackdump makefile~

compile:
	g++ -std=c++14 051_N_Queens.cpp
	./a.out

compwin:
	g++ -std=c++17 494_Target_Sum.cpp
	./a.exe


