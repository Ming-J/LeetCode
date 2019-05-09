

clean:
	rm *.*~ *.out makefile~

cleanwin:
	rm *.*~ *.exe a.exe.stackdump makefile~
	rm ./CodeForces/*.*~ ./CodeForces/*.exe ./CodeForces/a.exe.stackdump ./CodeForces/makefile~

compile:
	g++ -std=c++17 0211_Add_And_Search_Word.cpp
	./a.out

compwin:
	py clean.py
	clang-cl -Xclang -std=c++17 Longest_common_Subsequence.cpp -o a.exe
	./a.exe


