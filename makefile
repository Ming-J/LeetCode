
clean:
	rm *.*~ *.out makefile~

cleanwin:
	rm *.*~ *.exe a.exe.stackdump makefile~

compile:
	g++ -std=c++14 495_Teemo_Attacking.cpp
	./a.out

compwin:
	g++ -std=c++14 495_Teemo_Attacking.cpp
	./a.exe


