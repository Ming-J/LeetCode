
clean:
	rm *.*~ *.out makefile~

cleanwin:
	rm *.*~ *.exe a.exe.stackdump makefile~

compile:
	g++ -std=c++14 477_Total_Hamming_Distance.cpp
	./a.out

compwin:
	g++ -std=c++17 395_Longest_Substring_With_At_Least_K_Repeating_Characters.cpp
	./a.exe


