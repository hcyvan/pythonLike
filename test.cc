//This file is use to test the python-like classes
#include "pyList.h"
#include "myLib.h"
#include "element.h"
#include <iostream>
#include <vector>
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
/*
int main()
{
	element d;
	element e(0x7);
	int a;
	std::cin >> d;
	std::cout<<"d="<<d<<std::endl;
	std::cout<<"e="<<e<<std::endl;
	std::cout<<type(d)<<std::endl;
	std::cout<<type(e)<<std::endl;
}
*/
int main()  
{  
	Time t;
	Time p;
	t.start(__LINE__);
	for(int i=0;i<100000;++i)
			std::cout<<i<<std::endl;
	t.end(__LINE__);
	t.show();
}  
