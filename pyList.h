#ifndef PYLIST_H
#define PYLIST_H
#include <vector>
#include <initializer_list>
#include "py.h"
#include "myLib.h"

class List{
public:
	List()=default;
	//constructor: overload when the list of elements is the same type. eg: List a={1,2,3} and List b={"cheng","liu","wang"}
	template<typename T>
	List(std::initializer_list<T>);
	//constructor: overload when the list of elements is not the same type. eg: List a={1,1.3,"cheng",'c'}
	template<typename... Args>
	List(const Args&... rest);
	//copy constructor
	List(const List&);
	//copy assignment operator
	List & operator=(const List &);
	//test function
	void show_lst(); 
	//member function
	std::vector<std::string>::size_type pycount(const std::string &) const;
	template <typename T>
	void pyappend(const T&);
private:
	//push a list of elements to lst recursively
	template<typename T,typename...Args>
	void push_recur(const T&,Args&...);
	template<typename T>
	void push_recur(const T&);
	std::vector<std::string> lst;
};

template<typename T>
List::List(std::initializer_list<T> il)
{
	for(auto beg=il.begin();beg!=il.end();++beg)
		lst.push_back(num2string(*beg));
}
template<typename... Args>
List::List(const Args&... rest)
{
	this->push_recur(rest...);
}
template<typename T>
void List::push_recur(const T& t)
{
	lst.push_back(num2string(t));
}
template<typename T,typename...Args>
void List::push_recur(const T& t,Args&... rest)
{
	lst.push_back(num2string(t));
	push_recur(rest...);
}
//member function
template <typename T>
void List::pyappend(const T& rt)
{
	lst.push_back(num2string(rt));
}
#endif
