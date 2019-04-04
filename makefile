

clean:
	rm *.*~ *.out makefile~

cleanwin:
	rm *.*~ *.exe a.exe.stackdump makefile~
	rm ./CodeForces/*.*~ ./CodeForces/*.exe ./CodeForces/a.exe.stackdump ./CodeForces/makefile~

compile:
	g++ -std=c++17 1009_Complement_Of_Base_10_Integer.cpp
	./a.out

compwin:
	py clean.py
	clang-cl -Xclang -std=c++17 AD0001_StronglyConnected.cpp -o a.exe
	./a.exe


