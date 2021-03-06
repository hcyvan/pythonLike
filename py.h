#ifndef PY_H
#define PY_H
#include <sstream>
//setpy() :from python's set().
template<typename T>
T setpy( T container)
{
	sort(container.begin(),container.end());
	auto uniqueSet = unique(container.begin(),container.end());
	container.erase(uniqueSet,container.end());
	return container;
}
//is_py_int():
bool is_py_int(const std::string &str);
#endif
