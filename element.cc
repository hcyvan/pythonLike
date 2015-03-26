//如果去掉using std::string 则显示编译错误？？？？？
//不能用int等进行拷贝初始化
#include <iostream>
#include <string>
using std::string;
class element{
public:
	//constructor
	element():type(INT),ival(0){}
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
			new(&sval)std::string(t.sval);
			break;
	}
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
	if(type==STR) sval.~string();
	cval=c;
	type=CHAR;
	return *this;
}
element &element::operator=(int i)
{
	if(type==STR) sval.~string();
	ival=i;
	type=INT;
	return *this;
}
element &element::operator=(double d)
{
	if(type==STR) sval.~string();
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

//********************************88
int main()
{
	element a;
	a=1;
	a='b';
	a="cheng";
	element b=a;
}
