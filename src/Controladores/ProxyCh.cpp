#include "ProxyCh.hpp"

ProxyCh::ProxyCh(){}
ProxyCh::~ProxyCh(){}

int ProxyCh::isProxy(std::string proxyIp, std::string proxyPort){
	

		std::string comando = " sleep 0 | telnet " + proxyIp + " " + proxyPort + " > " + proxyIp + ":" + proxyPort + ".txt";
		system(comando.c_str());
		
		std::string tmpTelnel = proxyIp + ":" + proxyPort + ".txt";
		
		std::ifstream input(tmpTelnel.c_str());
		
		
		
		while(!input.eof()) 
		{
			char cadena[128];
			input.getline(cadena, 128);
			std::string tmp = cadena;
			int cadenaSize = tmp.length(); 
			std::string palabra = "";
			if (cadenaSize == 0){
				return -1;
				}
			for (int i = 0; i < cadenaSize; i++){
				
				palabra = palabra + cadena[i];
				if (palabra == "Connected"){
					std::string rmTmp = "rm " + proxyIp + ":" + proxyPort + ".txt";
					system(rmTmp.c_str());
					return 0;
					
					}
				}
		};
		
		std::string rmTmp = "rm " + proxyIp + ":" + proxyPort + ".txt";
		system(rmTmp.c_str());
	
		return -1;
	};
