clean:
	rm *.*~ *.out makefile~

cleanwin:
	rm *.*~ *.exe a.exe.stackdump makefile~

compile:
	g++ -std=c++11 714_Best_Time_To_Buy_And_Sell_Stock_With_Transaction_Fee.cpp
	./a.out
