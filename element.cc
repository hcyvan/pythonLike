//如果去掉using std::string 则显示编译错误？？？？？
//不能用int等进行拷贝初始化
#include <iostream>
#include <string>
using std::string;
class element{
	friend std::ostream &operator<<(std::ostream &,const element &);
public:
	//constructor
	element():type(INT),ival(0){}
	element(const char &c):type(CHAR),cval(c){};
	element(const int &i):type(INT),ival(i){};
	element(const double &d):type(DBL),dval(d){};
	explicit element(const std::string &s):type(STR),sval(s){};		//直接初始化std::string sval 是否有问题???
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
	/*
	void copyUnion(const char &);
	void copyUnion(const int &);
	void copyUnion(const double &);
	*/
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
			new(&sval)std::string(t.sval);				//???????????????
			//sval=t.sval;
			break;
	}
}
/*
void element::copyUnion(const char &c)
{
	cval=c;
	type=CHAR;
}
void element::copyUnion(const int &i)
{
	cval=i;
	type=INT;
}
void element::copyUnion(const double &d)
{
	cval=d;
	type=DBL;
}
*/
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
	element c=1;
	element d(1);
	std::string s="cheng";			//此处必须将“cheng”转换为std::string
	element e(s);
	std::cout<<a<<std::endl;
	std::cout<<c<<std::endl;
	std::cout<<e<<std::endl;
}
