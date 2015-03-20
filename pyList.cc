#include "pyList.h"
#include <iostream>
void List::show_lst()
{
	for(auto elem :lst)
		std::cout<<elem<< " ";
	std::cout<<std::endl;
}
//member function
std::vector<std::string>::size_type List::pycount(const std::string & rs) const
{
	return count(lst.begin(),lst.end(),rs);
}
