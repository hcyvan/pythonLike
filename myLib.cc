//myLib.cc
// This file include the defination of functions in myLib.h
// This file was complied to myLib.o and add to libmyLib.a
#include "myLib.h"
#include <stdexcept>
#include <iostream>
//add overload function in std spacename
namespace std{
	std::string to_string(const std::string &i)
	{
		return i;
	}
	std::string to_string(const char &i)
	{
		char s[2]={i,'\0'};	//turn char to char[];
		return s;
	}

}
void argcTest(const int argc, const int youNeed)
{
	if(argc != youNeed){
		std::cout << "You should enter "<<(youNeed-1)<<(youNeed>2?" arguments.":" argument.")<<std::endl;
		throw std::runtime_error("Worng argc!!!");
	}
}
std::string num2string(const int& i)
{	
	std::string str=std::to_string(i);
	return str;
}

//The defination of class Time in "myLib.h"
Time::Time():start_t(0),end_t(0),start_line(0),end_line(0),is_start(false),is_end(false){}
void Time::start(int i)
{
	start_t=clock();
	start_line=i;
	is_start=true;
}
void Time::end(int i)
{
	end_t=clock();
	end_line=i;
	is_end=true;
}
void Time::show() const
{
	if(!(is_start&&is_end))
		throw std::runtime_error("Time::start() or Time::end() is not used!");
	if(start_line!=0&&end_line!=0)
		std::cout<<"Line "<<start_line<<" to "<<"Line "<<end_line<<" use: ";
	else
		std::cout<<"Use: ";
	std::cout<<end_t-start_t<<"ms"<<std::endl;
}
