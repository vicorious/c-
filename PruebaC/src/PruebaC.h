/*
 * PruebaC.h
 *
 *  Created on: 28/11/2018
 *      Author: Alejandro Lindarte Castro
 */

#ifndef PRUEBAC_H_
#define PRUEBAC_H_


/**
 *
 */
namespace pruebabbva
{
	#include "Persona.h"
	#include "Libros.h"

	#define pi "3.1416"
	#define alejo "alejos";

	/**
	 *
	 *
	 *
	 */
	void por_valor()
	{
		std::cout << "------Por valor------" << "\n";

		Persona persona2;
		persona2.edad = 4;
		int edad_2 = persona2.getEdad2();//copia a la variable miembro "edad" de la clase "Persona"
		edad_2 = -1;
		std::cout << edad_2 << "\n";
		std::cout << persona2.getEdad2() << "\n";

	}//por_valor

	/**
	 *
	 *
	 *
	 */
	void por_referencia()
	{
		std::cout << "------Por referencia------" << "\n";

		Persona* persona = new Persona;
		persona->edad = 5;
		int* edad = persona->getEdad();//referencia a la variable miembro edad de la clase "Persona"
		edad = (int*)5;
		std::cout << edad << "\n";
		std::cout << persona->getEdad() << "\n";

		delete persona;
		delete edad;

	}//por_referencia

	/**
	 *
	 *
	 *
	 */
	void memoria()
	{
		std::cout << "------Memoria------" << "\n";

		double* pvalue  = NULL; // Apuntador inicializado en NULL
		pvalue  = new double;   // Peticion a la memoria para alojar la variable

		*pvalue = 29494.99;     // Almacena el valor en la direccion encontrada

		std::cout << "Valor de pvalue : " << *pvalue << std::endl;

		delete pvalue;         // Liberamos memoria.

	}//memoria

	/**
	 *
	 *
	 *
	 */
	void storage()
	{
		std::cout << "------Storage------" << "\n";

		/*
		 * se usa para decirle al compilador que guarde la variable en el registro de la RAM
		 * es decir, la variable tiene un tamaño igual al tamaño del registro y no puede usarse
		 * el modificador "&" ya que no tiene direccion en memoria
		 *
		 * Se usa solo para variables que necesiten acceso rapido como contadores por ejemplo
		 */
		register int millas;

		/**
		 * auto Es el default. esta puede ser usada solamente dentro de funciones y variables locales
		 *
		 *
		 */
		 int millas10;

		/**
		 * Static le indica al compilador que mantenga la variable local en existencia durante la vida util del programa
		 * en vez de estar creandola y destruyendola cada vez que entra y sale del alcance
		 * SOLO PARA VARIABLES GLOBALES
		 */
		static int millas3;

		/**
		 * Referencia variables globales que son visibles en toda la aplicación
		 *
		 */
		extern int millas4;


	}//storage

	/**
	 * Los modificadores son usados para alterar el comportamiento de un tipo de datos base
	 * esto para obtener resultados precisos para diferentes contextos
	 *
	 * Con el parametro de nombre "parametro_restringido" le informamos al compilador que dos hilos
	 * no pueden acceder a direcciones de memoria sobrepuestas
	 *
	 */
	void  tipos_modificadores(int *__restrict__ parametro_restringido)
	{
		std::cout << "------Tipos modificadores------" << "\n";
		short int i;           // a signed short integer
		short unsigned int j;  // an unsigned short integer

		j = 50000;

		i = j;
		std::cout << i << " " << j;
		// es -15536 50000 porque "50000" en patron de bites como entero sin asignacion equivale a "-15536"

		/*
		 * Con el modificador const, el objecto o variable no puede ser cambiado
		 * durante la ejecucion del programa;
		 *
		 */
		const std::string constante;

		/**
		 * Con volatile, le informamos al compilador que el valor de la variable puede cambiar
		 * por caminos no especificados en el programa
		 *
		 *
		 */
		volatile std::string nombre_que_puede_cambiar = "Alejo";


	}//tipos_modificadores

	/**
	 *
	 *
	 *
	 */
	void estructuras()
	{
		struct Books book1;

		const std::string titulo = "Duma key";
		const std::string autor = "Stephen King";

	}//estructuras

}//namespace pruebabbva


#endif /* PRUEBAC_H_ */
