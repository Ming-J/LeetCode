
clean:
	rm *.*~ *.out makefile~

cleanwin:
	rm *.*~ *.exe a.exe.stackdump makefile~

compile:
	g++ -std=c++14 417_Pacific_Atlantic_Water_Flow.cpp
	./a.out

compwin:
	g++ -std=c++17 494_Target_Sum.cpp
	./a.exe


