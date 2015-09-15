#include "ProxyCh.hpp"

ProxyCh::ProxyCh(){}
ProxyCh::~ProxyCh(){}

int ProxyCh::isProxy(std::string proxyIp, std::string proxyPort){
	
	
		std::string comando = " sleep 0 | telnet " + proxyIp + " " + proxyPort + " > " + proxyIp + ":" + proxyPort + ".txt";
		system(comando.c_str());
	
		return 0;
	};
