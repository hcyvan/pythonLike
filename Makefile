libmyLib.a:myLib.o
  ar -rcs libmyLib.a myLib.o
myLib.o:myLib.cc
	g++49 -std=c++11 -c -o myLib.o myLib.cc
clean:
	rm myLib.o
