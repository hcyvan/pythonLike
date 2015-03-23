test:test.cc libmyLib.a
	g++49 -std=c++11 test.cc -L./ -lmyLib -o test
libmyLib.a:myLib.o pyList.o
	ar -rcs libmyLib.a myLib.o pyList.o
myLib.o:myLib.cc
	g++49 -std=c++11 -c -o myLib.o myLib.cc
pyList.o:pyList.cc
	g++49 -std=c++11 -c -o pyList.o pyList.cc
.PHONY:clean
clean:
	rm -f myLib.o pyList.o
.PHONY:clean-all
clean-all:
	make clean
	rm -f libmyLib.a test
