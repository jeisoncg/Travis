#ifndef Extraccion_Sinonimos_hpp
#define Extraccion_Sinonimos_hpp

#include "Lectura.cpp"
#include "RelacionSinAnt.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;
class Extraccion_Sinonimos{
	
	public: 
	Extraccion_Sinonimos();
	~Extraccion_Sinonimos();
	struct relac_sinonimo {std::string palabra1; std::string palabra2;};
	struct relac_antonimo {std::string palabra1; std::string palabra2;};
    int adicionar_relacion_sinonimos(string sinonimos, string palabra);//recibe un string con el formato sinonimo1,sinonimo2,....,sinonimoN, (con una coma al final) y una palabra base
    int adicionar_relacion_antonimos(string antonimos, string palabra);//recibe un string con el formato antonimo1,antonimo2,....,antonimoN, (con una coma al final) y una palabra base
    int construir_sinonimos(char *cadena, string palabra);
    int construir_antonimos(char *cadena, string palabra);
    int extraer_sinonimos_antonimos(string ruta, string palabra);//la ruta debe contener la direccion de la carpeta donde se almacenan los .html, ejemplo: /home/user/Travis/src
    vector <relac_sinonimo> get_lista_sinonimos();
    vector <relac_antonimo> get_lista_antonimos();
    void RegistrarSinonimosBD(vector <RelacionSinAnt> relaciones, ConexionDB *conexion);
    vector <string> getSinonimos(void);
    vector <string> getAntonimos(void);
    
	private:
	
	vector <relac_sinonimo> lista_sinonimos;
    vector <relac_antonimo> lista_antonimos;
    
    
	
};


#endif 
