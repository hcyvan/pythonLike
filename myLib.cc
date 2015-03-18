//myLib.cc
// This file include the defination of functions in myLib.h
// This file was complied to myLib.o and add to libmyLib.a
#include "myLib.h"
#include <stdexcept>
#include <iostream>
//add overload function in std spacename
namespace std{
	std::string to_string(const std::string &i)
	{
		return i;
	}
	std::string to_string(const char &i)
	{
		char s[2]={i,'\0'};	//turn char to char[];
		return s;
	}

}
void argcTest(const int argc, const int youNeed)
{
	if(argc != youNeed){
		std::cout << "You should enter "<<(youNeed-1)<<(youNeed>2?" arguments.":" argument.")<<std::endl;
		throw std::runtime_error("Worng argc!!!");
	}
}
std::string num2string(const int& i)
{	
	std::string str=std::to_string(i);
	return str;
}
