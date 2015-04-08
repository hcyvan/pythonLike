#include "element.h"
void element::copyUnion(const element &t)
{
	switch(t.type){
		case element::CHAR:
			cval=t.cval;
			break;
		case element::INT:	
			ival=t.ival;
			break;
		case element::DBL:
			dval=t.dval;
			break;
		case element::STR:
			new(&sval)std::string(t.sval);				// placement new
			break;
	}
}
//constructor
element::element():type(INT),ival(0){}
element::element(const char &c):type(CHAR),cval(c){}
element::element(const int &i):type(INT),ival(i){}
element::element(const double &d):type(DBL),dval(d){}
element::element(const std::string &s):type(STR),sval(s){}
//copy-constructor
element::element(const element &t):type(t.type)
{
	copyUnion(t);
}
//copy-assignment operator
element &element::operator=(const element &t)
{
	if(type==STR && t.type!=STR)	
		sval.~string();
	if(type==STR && t.type==STR)	
		sval=t.sval;
	else
		copyUnion(t);
	type=t.type;
	return *this;
}
element &element::operator=(char c)
{
	if(type==STR)
		sval.~string();
	cval=c;
	type=CHAR;
	return *this;
}
element &element::operator=(int i)
{
	if(type==STR)
		sval.~string();
	ival=i;
	type=INT;
	return *this;
}
element &element::operator=(double d)
{
	if(type==STR)
		sval.~string();
	dval=d;
	type=DBL;
	return *this;
}
element &element::operator=(const std::string &s)
{
	if(type==STR)
		sval=s;
	else
		new(&sval) std::string(s);
	type=STR;
	return *this;
}
element::element(element &&t) noexcept:type(t.type)
{
	//现在不行，移动构造后没有消除原先的值 
	switch(t.type){
		case element::CHAR:
			cval=t.cval;
			break;
		case element::INT:	
			ival=t.ival;
			break;
		case element::DBL:
			dval=t.dval;
			break;
		case element::STR:
			new(&sval)std::string(t.sval);				// placement new
			break;
	}
}
//reload operator
std::ostream &operator<<(std::ostream &os,const element &e)
{
	switch(e.type){
		case element::CHAR:
			os<<e.cval;
			break;
		case element::INT:	
			os<<e.ival;
			break;
		case element::DBL:
			os<<e.dval;
			break;
		case element::STR:
			os<<e.sval;
			break;
	}
	return os;
}
//Anything is input as string...
std::istream &operator>>(std::istream &is,element &e)
{
	std::string buffer;
	is>>buffer;
	e=buffer;
	return is;
}
/*
//********************************88
int main()
{
	element a;
	a=1;
	a='b';
	a="cheng";
	element b=a;
	element d(1);
	std::string s="cheng";			//此处必须将“cheng”转换为std::string
	element e(s);
	std::cin>> e;
	std::cout<<a<<std::endl;
	std::cout<<d<<std::endl;
	std::cout<<e<<std::endl;
}
*/
