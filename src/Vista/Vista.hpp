#ifndef Vista_hpp
#define Vista_hpp

#include "../Controladores/Extraccion_Sinonimos.cpp"
#include "../Controladores/TorManager.cpp"
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
	
		Extraccion_Sinonimos *una_extraccion;
		vector <RelacionSinAnt> palabras_sinonimos_antonimos;
		Color color;
		string rutaArchivos;
		string rutaDiccionario;
		TorManager tormanager;
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
	    void extraer_una_palabra_sin_ant();//extrae los sinonimos y antonimos de una palabra y los imprime por pantalla
	    void imprimir_relaciones_sinonimos();
	    void imprimir_relaciones_antonimos();
	    void extraer_todas_relaciones_antonimos(int posInicial, int posFinal);
	    
	    public:
	    Vista();
		Vista(string db_name,string user,string pass,string host, string rutaArchivos, string rutaDiccionario);
		~Vista();
		void menu();
		
	
	};

#endif
