
clean:
	rm *.*~ *.out makefile~

cleanwin:
	rm *.*~ *.exe a.exe.stackdump makefile~

compile:
	g++ -std=c++14 535_Encode_And_Decode_TinyURL.cpp
	./a.out

compwin:
	g++ -std=c++14 84_Largest_Rectangle_In_Histogram.cpp
	./a.exe


