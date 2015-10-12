#include "RelacionSinAnt.hpp"
	 

	 
RelacionSinAnt::RelacionSinAnt(){};
RelacionSinAnt::RelacionSinAnt(std::string palabra,std::vector <std::string> sinonimos,std::vector <std::string> antonimos){
	
		this->palabra = palabra;
		this->sinonimos = sinonimos;
		this->antonimos = antonimos;
	};
RelacionSinAnt::~RelacionSinAnt(){};
		
void RelacionSinAnt::setPalabra(std::string palabra){this->palabra=palabra;};
std::string RelacionSinAnt::getPalabra(void){return this->palabra;};
void RelacionSinAnt::setSinonimos(std::vector <std::string> sinonimos){this->sinonimos = sinonimos;};
std::vector <std::string> RelacionSinAnt::getSinonimos(void){return this->sinonimos;};
void RelacionSinAnt::addSinonimo(std::string sinonimo){this->sinonimos.push_back(sinonimo);};
void RelacionSinAnt::setAntonimos(std::vector <std::string> antonimos){this->antonimos = antonimos;};
std::vector <std::string> RelacionSinAnt::getAntonimos(void){return this->antonimos;}; 
void RelacionSinAnt::addAntonimo(std::string antonimo){this->antonimos.push_back(antonimo);};
void RelacionSinAnt::print(void){
	
		std::cout << "{ " << this->palabra << ":" << std::endl;
		std::cout << "	Sinonimos:";
		int tmp_size = this->sinonimos.size();
		for (int i = 0; i < tmp_size;i++){
				if (i != 0){std::cout << ",";};
				std::cout << this->sinonimos[i];
			
			} std::cout <<";"<< std::endl;
		
		std::cout << "	Antonimos:";
	    tmp_size = this->antonimos.size();
		for (int i = 0; i < tmp_size;i++){
				if (i != 0){std::cout << ",";};
				std::cout << this->antonimos[i];
			
			} std::cout <<";"<< std::endl;
		
		std::cout<<"}"<<std::endl;
		
	};
