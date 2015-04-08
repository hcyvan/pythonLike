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
	element a;
	a=1;
	a='b';
	a="cheng";
	a=1;
	element b=a;
	element d(1);
	std::string s="cheng";			//此处必须将“cheng”转换为std::string
	element e(s);
	std::cin>> e;
	std::cout<<a<<std::endl;
	std::cout<<d<<std::endl;
	std::cout<<e<<std::endl;
}

