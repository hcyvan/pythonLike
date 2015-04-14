#include "element.h"
#include "py.h"
void element::copyUnion(const element &t)
{
	switch(t.type_id){
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
element::element():type_id(INT),ival(0){}
element::element(const char &c):type_id(CHAR),cval(c){}
element::element(const int &i):type_id(INT),ival(i){}
element::element(const double &d):type_id(DBL),dval(d){}
element::element(const std::string &s):type_id(STR),sval(s){}
//copy-constructor
element::element(const element &t):type_id(t.type_id)
{
	copyUnion(t);
}
//copy-assignment operator
element &element::operator=(const element &t)
{
	if(type_id==STR && t.type_id!=STR)	
		sval.~string();
	if(type_id==STR && t.type_id==STR)	
		sval=t.sval;
	else
		copyUnion(t);
	type_id=t.type_id;
	return *this;
}
element &element::operator=(char c)
{
	if(type_id==STR)
		sval.~string();
	cval=c;
	type_id=CHAR;
	return *this;
}
element &element::operator=(int i)
{
	if(type_id==STR)
		sval.~string();
	ival=i;
	type_id=INT;
	return *this;
}
element &element::operator=(double d)
{
	if(type_id==STR)
		sval.~string();
	dval=d;
	type_id=DBL;
	return *this;
}
element &element::operator=(const std::string &s)
{
	if(type_id==STR)
		sval=s;
	else
		new(&sval) std::string(s);
	type_id=STR;
	return *this;
}
/*
移动语义对于指针成员有意义,此处不合适
element::element(element &&t) noexcept:type_id(t.type_id)
{
	//现在不行，移动构造后没有消除原先的值 
	switch(t.type_id){
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
*/
//member function
int element::get_type_id() const
{
		return type_id;
}

//non-member function
const char *type(const element& t) 
{
	switch(t.get_type_id()){
			case 0:
				return "int";
			case 1:
				return "double";
			case 2:
				return "int";
			case 3:
				return "std::string";
	}
}
//reload operator
std::ostream &operator<<(std::ostream &os,const element &e)
{
	switch(e.type_id){
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
//Anything is input as string and int.........................................???
std::istream &operator>>(std::istream &is,element &e)
{
	std::string buffer;
	is>>buffer;
	if(is_py_int(buffer))
		e=stoi(buffer);
	else
		e=buffer;
	return is;
}
