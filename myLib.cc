//myLib.cc
// This file include the defination of functions in myLib.h
// This file was complied to myLib.o and add to libmyLib.a
#include "myLib.h"
#include <stdexcept>
#include <iostream>
void argcTest(const int argc, const int youNeed)
{
	if(argc != youNeed){
		std::cout << "You should enter "<<(youNeed-1)<<(youNeed>2?" arguments.":" argument.")<<std::endl;
		throw std::runtime_error("Worng argc!!!");
	}
}
