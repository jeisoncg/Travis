#ifndef Lectura_hpp
#define Lectura_hpp

#include "ConexionBD.cpp"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdlib.h>

using namespace std;
using std::vector;
using std::string;

class Lectura {
	
	private:
	
	vector <string> entrada;
	vector <string> palabras;
	char cadena[128]; 
	
	public:
	Lectura();
	~Lectura();
	void Leer(string file);
	void MostrarPalabras();
	vector <string> getPalabras();
	void RegistrarPalabrasBD(vector <string> palabras, ConexionDB *conexion);
	
	};

#endif

