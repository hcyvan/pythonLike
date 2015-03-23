#include "pyList.h"
#include <iostream>
#include <algorithm>
void List::show_lst()
{
	for(auto elem :lst)
		std::cout<<elem<< " ";
	std::cout<<std::endl;
}
//member function
std::vector<std::string>::size_type List::pycount(const std::string & rs) const
{
	return std::count(lst.begin(),lst.end(),rs);
}
//copy constructor
List::List(const List &rhs):lst(rhs.lst){}
//copy assignment operator
List & List::operator=(const List &rhs) 
{
	lst=rhs.lst;
	return *this;
}
