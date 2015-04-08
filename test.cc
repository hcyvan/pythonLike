//This file is use to test the python-like classes
#include "pyList.h"
#include "element.h"
#include <iostream>
/*
int main()
{
	List a={1,"cheng",'z',"cheng",1.2};
	List b,c;
	b=c=a;
	a.show_lst();
	b.show_lst();
	c.show_lst();
	a.pyappend("yi");
	a.show_lst();
	b.show_lst();
	c.show_lst();
	std::cout <<a.pycount("cheng")<<std::endl;
}
*/
int main()
{
	element c("hhh");
	element f=std::move(c);
	std::cout<<"c="<<c<<std::endl;
	std::cout<<"f="<<f<<std::endl;
}

