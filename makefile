
clean:
	rm *.*~ *.out makefile~

cleanwin:
	rm *.*~ *.exe a.exe.stackdump makefile~

compile:
	g++ -std=c++14 331_Verify_Preorder_Serialzation_Of_A_Binary_Tree.cpp
	./a.out

