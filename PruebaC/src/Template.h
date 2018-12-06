#include <iostream>
#include <string>

template <typename H>
inline H const& Maximo (H const& a, H const& b)
{
	return a < b ? b: a;

}//Maximo
