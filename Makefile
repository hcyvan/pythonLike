libmyLib.a:myLib.o pyList.o
	ar -rcs libmyLib.a myLib.o pyList.o
myLib.o:myLib.cc
	g++49 -std=c++11 -c -o myLib.o myLib.cc
pyList.o:pyList.cc
	g++49 -std=c++11 -c -o pyList.o pyList.cc
.PHONY:clean
clean:
	rm myLib.o pyList.o
