#include "py.h"
#include <cctype>
bool is_py_int(const std::string &str)
{
		for(char c:str)
				if(!isdigit(c))
						return false;
		return true; 
}
