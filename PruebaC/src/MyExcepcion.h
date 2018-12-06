#include <iostream>
#include <exception>
using namespace std;

/**
 *
 */
struct MyException : public exception
{
   const char * que_paso () const throw ()
   {
      return "C++ Excepcion";
   }

};//NoBorrar
