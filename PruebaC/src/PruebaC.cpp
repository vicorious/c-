//============================================================================
// Name        : PruebaC.cpp
// Author      : Alejandro Lindarte Castro
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include "PruebaC.h"
#include "MyExcepcion.h"
#include <csignal>
#include <signal.h>
#include <thread>

/**
 * Main APP
 */
int main()
{

	pruebabbva::por_valor();

	pruebabbva::por_referencia();

	pruebabbva::memoria();

	pruebabbva::tipos_modificadores((int*)5);

	pruebabbva::sobrecarga();

	pruebabbva::polimorfismo();

	//Errores
	try
	{
		pruebabbva::manejo_errores(2, 0);

	}catch(const char* msg)
	{
		std::cerr << msg << std::endl;
	}

	//Excepciones propias
	try
	{
		throw MyException();

	} catch(MyException& e)
	{
		std::cout << "MyException Capturada" << std::endl;
		std::cout << e.que_paso() << std::endl;

	} catch(std::exception& e)
	{
		//Other errors
	}

	//template
	pruebabbva::generic_template();

	//preprocesadores
	pruebabbva::pre_procesadores();

	return 0;

}//main

