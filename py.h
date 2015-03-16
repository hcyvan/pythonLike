#ifndef PY_H
#define PY_H
#include <sstream>
//setpy() :from python's set()
template<typename T> T setpy( T container)
{
	sort(container.begin(),container.end());
	auto uniqueSet = unique(container.begin(),container.end());
	container.erase(uniqueSet,container.end());
	return container;
}
//turn number to string
template<typename T> std::string num2string(const T& i)
{
	std::ostringstream out;
	out << i;
	return out.str();
}
#endif
