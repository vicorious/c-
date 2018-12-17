/*
 * Figura.h
 *
 *  Created on: 3/12/2018
 *      Author: User
 */

#ifndef FIGURA_H_
#define FIGURA_H_
#include <iostream>

/**
 *
 */
class Figura
{
	protected:
      int width = 0, height = 0;
	public:
		Figura();//constructor
		Figura(int a = 0, int b = 0)
		{
			width = a;
			height = b;
		}//constructor

		virtual ~Figura()
		{
			this->~Figura();
		}//destructor

		int area()
		{
			std::cout << "Esta es la clase FIGURA" << "\n";
			return 0;

		}//area

};//noBorrar

/**
 *
 */
class Rectangulo: public Figura
{
	public:
		Rectangulo(int a = 0, int b = 0):Figura(a, b){}//constructor heredado

	int area()
	{
		std::cout << "Area del rectangulo" << std::endl;

		return (width * height);

	}//area

};//NoBorrar

/**
 *
 */
class Triangulo: public Figura
{
	public:
		Triangulo(int a = 0, int b = 0):Figura(a, b){}//constructor heredado

	int area()
	{
		std::cout << "Area del triangulo" << std::endl;

		return (width * height) / 2;

	}//area

};//NoBorrar

#endif /* FIGURA_H_ */
