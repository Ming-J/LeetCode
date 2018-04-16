
clean:
	rm *.*~ *.out makefile~

cleanwin:
	rm *.*~ *.exe a.exe.stackdump makefile~

compile:
	g++ -std=c++14 501_Find_Mode_In_Binary_Search_Tree.cpp
	./a.out

compwin:
	g++ -std=c++17 494_Target_Sum.cpp
	./a.exe


