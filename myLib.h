#ifndef MYLIB_H
#define MYLIB_H
#include <iostream>
#define ERRORMESSAGE std::cerr<<"Error:"<<__FILE__<<" : in function "<<__func__<<" at line "<<__LINE__<<std::endl
#define DONE std::cout<<__func__<<" is done! DONE is in "<<__FILE__<<", line "<<__LINE__<<std::endl
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
//setpy() :from python's set()
template<typename T>
T setpy( T container)
{
	sort(container.begin(),container.end());
	auto uniqueSet = unique(container.begin(),container.end());
	container.erase(uniqueSet,container.end());
	return container;
}
#endif
