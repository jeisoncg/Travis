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
	
	ofstream myfile;
	
	
	ifstream input(url.c_str());
		
		while(!input.eof()) 
		{
			char cadena[128];
			input.getline(cadena, 128);
			string tmp = cadena;
			if (tmp != ""){
			int tmp_size = tmp.length();
			
				string ipProxy = "";
				string puerto = "";
				bool flag_puntos_dobles = false; //Indica cuando se debe dejar de escribir la ip y pasa a puerto: Ver If
				int i=0;
				for (i = 0 ; i < tmp_size ; i++)
				{
					if (cadena[i] == ' '){
						i = tmp_size;
						}
					if (cadena[i] == '	'){
						i = tmp_size;
						}
					if (cadena[i] == ':'){
						flag_puntos_dobles = true;
						i++;
					}
					if (flag_puntos_dobles == false){
						ipProxy +=  cadena[i];
					}
					if (flag_puntos_dobles == true){
						puerto += cadena[i];
					}
					
				}
				
				int esValido = -1;
				int pingValido = Proxy::ping(ipProxy);
				
				if (pingValido == 0){
					esValido = this->validadorProxy.isProxy(ipProxy,puerto);
					}
				
				if (esValido == 0){
						cout<< this->color.GREEN <<" [ADICIONADO] " << this->color.RESET << ipProxy + ":" + puerto << this->color.BOLDBLUE << " --> to proxiesOk.txt" << this->color.RESET <<endl;
						myfile.open ("proxiesOK.txt");
						
						string proxiesOk = "";
						this->proxyUrl.push_back(cadena);
						int proxyesSize = this->proxyUrl.size();
						for (int i = 0 ; i < proxyesSize;i++){
							
							proxiesOk+= this->proxyUrl[i] + "\n";
							
							}
						myfile << proxiesOk << "\n";
						myfile.close();
					}else{
						cout<<this->color.BOLDRED <<" [OFFLINE] " << this->color.RESET << ipProxy + ":" + puerto <<endl;
						}
				
			}
		}
	
		
	
	};
	
int Proxy::ping(std::string target)
{
	string comando = "ping -c 1 " + target;
	
	int retorno = system(comando.c_str());
	cout << comando << " RETORNO: " << retorno<<endl;
	if (retorno == 0)
	{
		return 0;
		}

return -1;
}

string Proxy::retornar_url_sin_puerto(string target)
{
	int size=target.size();
	string target2="";
	for(int i=0; i<size;i++)
	{
		if(target.at(i)!=':')
		{
			target2=target2+target.at(i);
		}
		else{
			i=target.size();
		}
	}
	return target2;
}
