#include "Proxy.hpp"

Proxy::Proxy(){}
Proxy::~Proxy(){}

string Proxy::get_ProxyUrl(int posicion){
	
	int size_proxyUrl = this->proxyUrl.size();
	if ((posicion>=0)&&(posicion<size_proxyUrl)){
		return this->proxyUrl[posicion];
		}
		return "-1";
	};
	
int Proxy::get_TotalProxiesAlmacenados(void){return this->proxyUrl.size();};
void Proxy::set_ProxyUrl(string url){
	
		this->proxyUrl.push_back(url);
	
	};

void Proxy::set_ProxyUrlDesdeArchivo(string url){
	
	
	ifstream input(url.c_str());
		
		while(!input.eof()) 
		{
			char cadena[128];
			input.getline(cadena, 128);
			string tmp = cadena;
			
		
			};
	
	
	};
	
int Proxy::ping(string target)
{
	string comando = "ping -c 1 " + target;
	int retorno = system(comando.c_str());
	cout<<retorno;

return 0;
}

