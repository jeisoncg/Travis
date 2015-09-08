#ifndef Vista_hpp
#define Vista_hpp

#include "Lectura.cpp"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdlib.h>


using namespace std;
using std::vector;
using std::string;

class Vista{
	
	private:
	
		Lectura lectura;
		ConexionDB *conexion;
		
		void leerPalabras();
		void mostrarPalabras();
		void registrarPalabras();
		void realizarConsulta(string consulta);
	
	public:
		Vista();
		~Vista();
		void menu();
		
	
	};

#endif
