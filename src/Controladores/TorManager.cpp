#include "TorManager.hpp"

TorManager::TorManager(){}
TorManager::~TorManager(){}

bool TorManager::isTorRunning(void){

		system("ps u > prcs.txt");
		
		std::ifstream input("prcs.txt");
		
		while(!input.eof()) 
		{
			char cadena[500];
			input.getline(cadena, 500);
			std::string tmp = cadena;
			//std::cout<<tmp<<std::endl;//Muestra los procesos.
			int tmp_size = tmp.length();
			std::string cadenaTMP = "";
			std::vector <std::string> palabrasTMP;
			for(int i = 0; i < tmp_size-3; i++){
				
				if ((cadena[i] == ' ')&&(cadena[i+1] == 't')&&(cadena[i+2] == 'o')&&(cadena[i+3] == 'r')){
					return true;
				}
				
			
			}
	
		
		}
		
	return false;
}

void TorManager::startHttpProxy(std::string portTor, std::string portHttp){
	
		std::string comando = "http-proxy/bin/dg9_9_13 delegated -P" + portHttp + " SERVER=http SOCKS=localhost:" + portTor + " ADMIN=tor@tor.com";
		system(comando.c_str());
	
	}

void TorManager::get_New_Tot_IP_Address(void){
	
		std::string comando = "java -jar tor-manager/dist/tor-manager.jar";
		system(comando.c_str());
	
	};
