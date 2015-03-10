#include "pyList.h"
#include <iostream>
void List::show_lst()
{
	for(auto elem :lst)
		std::cout<<elem<< " ";
	std::cout<<std::endl;
}
