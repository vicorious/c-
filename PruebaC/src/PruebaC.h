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
 * Namespace que contiene pruebas unitarias de sintaxis c++
 *
 */
namespace pruebabbva
{
	#include "Persona.h"
	#include "Libros.h"
	#include "Figura.h"
	#include "Template.h"
	#include "Preprocesadores.h"
	#include "MultiTasking.h"
	#include <vector>
	#include <ctime>
	/**
	 *
	 * Por valor (Objetos)
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
	 * Paso por referencia (Apuntadores)
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
	 * Manejo de memoria
	 *
	 * Todas las variables que son declaradas dentro de una funcion, tomaran parte de la pila "stack"
	 *
	 * Existe memoria inutilizada que puede ser usada para alojar memoria dinamica cuando el programa corra
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
	 * no pueden acceder a direcciones de memoria sobrepuestas del parametro
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
	 * Estructuras complejas
	 *
	 */
	void estructuras()
	{
		std::cout << "------Estructuras------" << "\n";

		struct Books book1;

		const std::string titulo = "Duma key";
		const std::string autor = "Stephen King";

	}//estructuras

	/**
	 *
	 * Sobrecarga de metodos
	 *
	 *
	 * SI SE PUEDEN SOBRECARGAR
	 *  +	-	*	/	%	^
	 *  &	|	~	!	,	=
	 *  <	>	<=	>=	++	--
	 * <<	>>	==	!=	&&	||
	 * +=	-=	/=	%=	^=	&=
	 * |=	*=	<<=	>>=	[]	()
	 * ->	->*	new	new []	delete	delete []
	 *
	 * NO SE PUEDEN SOBRECARGAR
	 *
	 * ::	.*	.	?:
	 *
	 */
	void sobrecarga()
	{
		std::cout << "------Sobrecarga------" << "\n";

		Persona persona1;
		persona1.edad = 15;
		persona1.nombre = "Alejo";

		Persona persona2;
		persona2.edad = 12;
		persona2.nombre = "Nathalia";

		/**
		 * Aqui se hace el llamado implicito a "operator+"
		 */
		Persona persona3 = persona1 + persona2;

		std::cout << persona3.edad << "\n";
		std::cout << persona3.nombre << "\n";

	}//sobrecarga

	/**
	 *
	 */
	void polimorfismo()
	{
		Figura* figura;
		Rectangulo rectangulo(10, 7);
		Triangulo triangulo(10, 5);

		//Guardamos la direccion del rectangulo
		figura = &rectangulo;

		std::cout << figura->area() << std::endl;

		// Guardamos la direccion del triangulo
		figura = &triangulo;

		std::cout << figura->area() << std::endl;

	}//polimorfismo

	/**
	 * con virtual, le pedimos al compilador que no haga un enlace a esta funcion
	 * ya que PUEDE tener mas de una sobrecarga
	 * El ejemplo mas claro son los constructores
	 *
	 */
	//virtual void virtual_function(){}//virtual_function

	/**
	 *
	 */
	double manejo_errores(int a, int b)
	{
		//lanzando excepciones
		if(b == 0)
		{
			throw "No se puede dividir entre cero";
		}

		return (a/b);

	}//manejo_errores

	/**
	 *
	 */
	void generic_template()
	{
		int i = 39;
		int j = 20;
		std::cout << "Maximo(i, j): " << Maximo(i, j) << std::endl;

		double f1 = 13.5;
		double f2 = 20.7;
		std::cout << "Maximo(f1, f2): " << Maximo(f1, f2) << std::endl;

		std::string s1 = "Hello";
		std::string s2 = "World";
		std::cout << "Maximo(s1, s2): " << Maximo(s1, s2) << std::endl;

	}//generic_template

	/**
	 *
	 * Son directivas que le indican instruciones personalizadas al compilador antes de compilar
	 *
	 */
	void pre_procesadores()
	{
		std::cout << "Valor de PI es :" << PI << std::endl;

		int i, j;
		i = 100;
		j = 30;

		std::cout << "El minimo es: " << MIN(i,j) << std::endl;

		#ifdef DEBUG
			std::cerr << "Debug activado para la función" << std::endl;
		#endif

	}//pre_procesadores

	/**
	 * Standard Library
	 */
	void STL_vector()
	{
		//Vector
		std::vector<int> vec;
		int i;

		// display the original size of vec
		std::cout << "vector size = " << vec.size() << std::endl;

		for(i = 0; i < 5; i++)
		{
			vec.push_back(i);
		}

		// display extended size of vec
		std::cout << "extended vector size = " << vec.size() << std::endl;

		// access 5 values from the vector
		for(i = 0; i < 5; i++)
		{
			std::cout << "value of vec [" << i << "] = " << vec[i] << std::endl;
		}

		// use iterator to access the values
		std::vector<int>::iterator v = vec.begin();

		while( v != vec.end())
		{
			std::cout << "value of v = " << *v << std::endl;
			v++;
		}

	}//STL_vector

	/**
	 *
	 */
	void date_use()
	{
		// current date/time based on current system
		time_t now = time(0);

		// convert now to string form
		char* dt = ctime(&now);

		std::cout << "The local date and time is: " << dt << std::endl;

		// convert now to tm struct for UTC
		tm *gmtm = gmtime(&now);
		dt = asctime(gmtm);
		std::cout << "The UTC date and time is:"<< dt << std::endl;

	}//date_use

	/**
	 * La multi tarea basada en procesos lanza concurrentes ejecuciones de programas.
	 * La multi tarea basada en hilos se ocupa de la ejecucion concurrente de piezas del mismo software
	 *
	 */
	/*void multitasking()
	{


	}//multitasking*/


}//namespace pruebabbva


#endif /* PRUEBAC_H_ */
