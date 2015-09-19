#ifndef Vista_hpp
#define Vista_hpp

#include "../Controladores/Lectura.cpp"
#include "../Controladores/Proxy.cpp"
#include "../Controladores/http.cpp"
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
	
		Color color;
	
		Lectura lectura;
		ConexionDB *conexion;
		http descargas;
		Proxy proxy;
		void leerPalabras();
		void mostrarPalabras();
		void registrarPalabras();
		void realizarConsulta(string consulta);
	    void mostrar_lista_proxis(); //muestra los  proxis existentes en proxis.txt
	    void descargar_todos_sinonimos();
	    void cargar_proxis();
	    
	public:
		Vista();
		~Vista();
		void menu();
		
	
	};

#endif
