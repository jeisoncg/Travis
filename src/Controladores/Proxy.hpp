#ifndef Proxy_hpp
#define Proxy_hpp


#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

class Proxy{


	private:

		vector <string> proxyUrl;//El formato de cada linea del vector es: 127.0.0.1:8080 por poner un ejemplo.
		void set_ProxyUrl(string url);
		
	public:

		Proxy();
		~Proxy();
		string get_ProxyUrl(int posicion); //retorna el proxy ubicado en la posicion indicada
		int get_TotalProxiesAlmacenados(void); //retorna cuantos proxys hay almacenados
		string retornar_url_sin_puerto(string url); //recibe una url con puerto y la devuelve sin este
		void set_ProxyUrlDesdeArchivo(string url); //construye un vector de proxys desde un archivo de texto
		int ping(string target); //verifica si un objetivo responde a la solicitud ping y retorna 0 en caso de ser afirmativo
};

#endif
