#ifndef MYLIB_H
#define MYLIB_H
#include <iostream>
#define ERRORMESSAGE std::cerr<<"Error:"<<__FILE__<<" : in function "<<__func__<<" at line "<<__LINE__<<std::endl
//check the argc of main
void argcTest(const int argc, const int youNeed);
//print the elements of a container
template<typename T>
void show(const T &container)
{
	for(auto element:container){
		std::cout << element <<" ";
	}
	std::cout << std::endl;
}
#end
