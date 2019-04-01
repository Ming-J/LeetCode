

clean:
	rm *.*~ *.out makefile~

cleanwin:
	rm *.*~ *.exe a.exe.stackdump makefile~
	rm ./CodeForces/*.*~ ./CodeForces/*.exe ./CodeForces/a.exe.stackdump ./CodeForces/makefile~

compile:
	g++ -std=c++17 1008_Construct_BST_Preorder.cpp
	./a.out

compwin:
	clang-cl -std=c++1z 886_Possible_Bipartition.cpp -o a.exe
	./a.exe


