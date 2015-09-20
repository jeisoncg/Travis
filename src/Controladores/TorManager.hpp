#ifndef TorManager_hpp_
#define TorManager_hpp_

#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
class TorManager {
	
		public:
		TorManager();
		~TorManager();
		bool isTorRunning(void);
		void startHttpProxy(std::string portTor, std::string portHttp);
		void get_New_Tot_IP_Address(void);
	
	
	};

#endif
