/*
 * Persona.cpp
 *
 *  Created on: 3/12/2018
 *      Author: User
 */

#include <iostream>

/**
 *
 *
 *
 */
class Persona
{
	private:
	public:
		int edad = 0;
		std::string nombre;

		//Constructores

		Persona()
		{
			std::cout << "Constructor llamado" << std::endl;
		}
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


