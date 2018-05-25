
clean:
	rm *.*~ *.out makefile~

cleanwin:
	rm *.*~ *.exe a.exe.stackdump makefile~

compile:
	g++ -std=c++14 0662v2_Maximum_Width_Of_Binary_Tree.cpp
	./a.out

compwin:
	g++ -std=c++17 086_Partition_List.cpp
	./a.exe


