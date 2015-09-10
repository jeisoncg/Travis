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
		string get_ProxyUrl(int posicion);
		int get_TotalProxiesAlmacenados(void);
		
		void set_ProxyUrlDesdeArchivo(string url);
		int ping(string target);
};

#endif
