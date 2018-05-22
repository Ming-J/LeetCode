
clean:
	rm *.*~ *.out makefile~

cleanwin:
	rm *.*~ *.exe a.exe.stackdump makefile~

compile:
	g++ -std=c++14 137_Single_Number_II.cpp
	./a.out

compwin:
	g++ -std=c++17 137_Single_Number_II.cpp
	./a.exe


