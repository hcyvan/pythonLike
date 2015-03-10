#ifndef PYLIST_H
#define PYLIST_H
#include <vector>
#include <initializer_list>
#include "py.h"
#include "myLib.h"

class List{
public:
	List()=default;
	//List a={"a","bc"} or List i={1,2,3} or...
	template<typename T> List(std::initializer_list<T> il)
	{
		for(auto beg=il.begin();beg!=il.end();++beg){
			std::string a=num2string(*beg);
			lst.push_back(a);
		}
	}
	void show_lst();                    //test function
private:
	std::vector<std::string> lst;
};
#endif
