// myLib.h
// This file include some Macros and the declearation of some useful functions
#ifndef MYLIB_H
#define MYLIB_H
#include <iostream>
#include <sstream>
#include <time.h>
#include <stdexcept>
#define ERRORMESSAGE std::cerr<<"Error:"<<__FILE__<<" : in function "<<__func__<<" at line "<<__LINE__<<std::endl
#define DONE std::cout<<__func__<<" is done! DONE is in "<<__FILE__<<", line "<<__LINE__<<std::endl
//add overload function in std spacename
namespace std{
	//now the argument of "to_string" can be string and char
	std::string to_string(const std::string &);
	std::string to_string(const char &);
}
//check the argc of main
void argcTest(const int argc, const int youNeed);
//print the elements of a container
template<typename T> void show(const T &container)
{
	for(auto element:container){
		std::cout << element <<" ";
	}
	std::cout << std::endl;
}
//turn number to string
//overload when the argument is "const int&"
std::string num2string(const int& i);
//overload when the argument is the other type
template<typename T> std::string num2string(T i)
{
	std::ostringstream out;
	out << i;
	return out.str();
}
//Time is a class to calculate the efficiency of some lines of code
class Time{
public:
	Time();
	Time(const Time &)=delete;
	Time &operator=(const Time &)=delete;
	//member function
	void start(int i=0);
	void end(int i=0);
	void show() const;
private:
	clock_t start_t;
	clock_t end_t;
	int start_line;
	int end_line;
	bool is_start;
	bool is_end;
};
#endif
