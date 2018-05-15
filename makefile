
clean:
	rm *.*~ *.out makefile~

cleanwin:
	rm *.*~ *.exe a.exe.stackdump makefile~

compile:
	g++ -std=c++14 015_3Sum.cpp
	./a.out

compwin:
	g++ -std=c++17 042_Trapping_Rain_Water.cpp
	./a.exe


