//如果去掉using std::string 则显示编译错误？？？？？
// 用placement new获得std::string指针，不能用~string()析构，以至于不能用～element()析构？？？
#include <iostream>
#include <string>
using std::string;
class element{
	friend std::ostream &operator<<(std::ostream &,const element &);
public:
	//constructor
	element():type(INT),ival(0){}
	explicit element(const char &c):type(CHAR),cval(c){};
	explicit element(const int &i):type(INT),ival(i){}
	explicit element(const double &d):type(DBL),dval(d){}
	explicit element(const std::string &s):type(STR),sval(s){}
	//copy constructor
	element(const element &t):type(t.type){copyUnion(t);}
	//copy-assignment operator
	element &operator=(const element &);
	element &operator=(char);
	element &operator=(int);
	element &operator=(double);
	element &operator=(const std::string &);
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
//copy-constructor
	

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
	std::cout<<a<<std::endl;
	std::cout<<d<<std::endl;
	std::cout<<e<<std::endl;
	e.~element();
}
