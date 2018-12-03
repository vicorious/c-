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
		std::string nombre;
	public:
		int edad = 0;

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

};//NoBorrar


