//如果去掉using std::string 则显示编译错误？？？？？
// 用placement new获得std::string指针，不能用~string()析构，以至于不能用～element()析构？？？
#ifndef ELEMENT_H
#define ELEMENT_H
#include <iostream>
#include <string>
using std::string;
class element{
	friend std::ostream &operator<<(std::ostream &,const element &);
	friend std::istream &operator>>(std::istream &,element &);
public:
	//constructor
	element();
	explicit element(const char &);
	explicit element(const int &);
	explicit element(const double &);
	explicit element(const std::string &);
	//copy constructor
	element(const element &);
	//copy-assignment operator
	element &operator=(const element &);
	element &operator=(char);
	element &operator=(int);
	element &operator=(double);
	element &operator=(const std::string &);
	//move constructor -std=c++11
	element(element &&) noexcept;
	//destructor
	~element(){if(type==STR) sval.~string();}
	//reload operator
private:
	enum {INT,CHAR, DBL,STR} type;
	union{
		char cval;
		int ival;
		double dval;
		std::string sval;
	};
	void copyUnion(const element &);
};
#endif
