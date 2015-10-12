 #ifndef RelacionSinAnt_hpp_
 #define RelacionSinAnt_hpp_
 
#include <string>
#include <vector>
#include <iostream>
 
 class RelacionSinAnt {
	 
	 
	 private:
	 
		std::string palabra;
		std::vector <std::string> sinonimos;
		std::vector <std::string> antonimos;
	 
	 public:
	 
		RelacionSinAnt();
		RelacionSinAnt(std::string palabra,std::vector <std::string> sinonimos,std::vector <std::string> antonimos);
		~RelacionSinAnt();
		
		void setPalabra(std::string palabra);
		std::string getPalabra(void);
		void setSinonimos(std::vector <std::string> sinonimos);
		std::vector <std::string> getSinonimos(void);
		void addSinonimo(std::string sinonimo);
		void setAntonimos(std::vector <std::string> antonimos);
		std::vector <std::string> getAntonimos(void);
		void addAntonimo(std::string antonimo);
		
		void print(void);
	 
	 };
 
 #endif
