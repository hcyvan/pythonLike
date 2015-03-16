// myLib.h
// This file include some Macros and the declearation of some useful functions
#ifndef MYLIB_H
#define MYLIB_H
#include <iostream>
#include <sstream>
#define ERRORMESSAGE std::cerr<<"Error:"<<__FILE__<<" : in function "<<__func__<<" at line "<<__LINE__<<std::endl
#define DONE std::cout<<__func__<<" is done! DONE is in "<<__FILE__<<", line "<<__LINE__<<std::endl
//check the argc of main
void argcTest(const int argc, const int youNeed);
//print the elements of a container
template<typename T> void show(const T &container)
{
	for(auto element:container){
		std::cout << element <<" ";
	}
	std::cout << std::endl;
}
//turn number to string
template<typename T> std::string num2string(T i)
{
	std::ostringstream out;
	out << i;
	return out.str();
}
#endif
