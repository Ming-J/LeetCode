

clean:
	rm *.*~ *.out makefile~

cleanwin:
	rm *.*~ *.exe a.exe.stackdump makefile~
	rm ./CodeForces/*.*~ ./CodeForces/*.exe ./CodeForces/a.exe.stackdump ./CodeForces/makefile~

compile:
	g++ -std=c++17 1017_Convert_To_Base_-2.cpp
	./a.out

compwin:
	py clean.py
	clang-cl -Xclang -std=c++17 1010_Pairs_Of_Songs_With_Total_Durations_Divisible_By_60.cpp -o a.exe
	./a.exe


