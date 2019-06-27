

clean:
	rm *.* ~*.out makefile~

cleanwin:
	rm *.*  ~*.exe a.exe.stackdump makefile~
	rm./CodeForces/*.*~ ./CodeForces/*.exe ./CodeForces/a.exe.stackdump ./CodeForces/makefile~

compile:
	g++ -std=c++17 1072_Flip_Columns_For_Maximum_Number_Of_Equal_Rows.cpp
	./a.out

compwin:
	py clean.py
	clang-cl -Xclang -std=c++17 1071_Greatest_Common_Divisor_Of_Strings.cpp -o a.exe
	./a.exe


