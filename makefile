
clean:
	rm *.*~ *.out makefile~

cleanwin:
	rm *.*~ *.exe a.exe.stackdump makefile~
	rm ./CodeForces/*.*~ ./CodeForces/*.exe ./CodeForces/a.exe.stackdump ./CodeForces/makefile~

compile:
	g++ -std=c++17 0981_Time_Based_Key_Value_Store.cpp
	./a.out

compwin:
	g++ -std=c++17 886_Possible_Bipartition.cpp
	./a.exe


