/*
 * Persona.cpp
 *
 *  Created on: 3/12/2018
 *      Author: User
 */

#include <iostream>

/**
 *
 * LAS CLASES ABSTRACTAS SON CLASES CON EL MISMO TEMPLATE SINTACTICO. SOLO CAMBIA QUE AL MENOS
 * DEBE TENER UNA FUNCION PURAMENTE VIRTUAL "virtual keyword"
 *
 */
class Persona
{
	//encapsulamiento protegido
	protected:
	//encapsulamiento privado
	private:
	//encapsulamiento publico
	public:
		int edad = 0;
		std::string nombre;

		//Constructores
		Persona()
		{
			std::cout << "Constructor llamado" << std::endl;
		}

		//Destructor
		~Persona()
		{
			std::cout << "Destructor llamado" << std::endl;
		}

		//Getters and setters

		int* getEdad()
		{
			return &edad;
		}
		int getEdad2()
		{
			return edad;
		}

		/**
		 *
		 * Sobrecarga para la suma de dos personas
		 *
		 */
		Persona operator+(const Persona& b)
		{
			Persona persona;
			persona.nombre = this->nombre + b.nombre;
			persona.edad = this->edad + b.edad;
			return persona;

		}//operator+

};//NoBorrar


