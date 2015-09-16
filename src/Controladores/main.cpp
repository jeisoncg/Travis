#include "ProxyCh.cpp"
int main(void){
	
	ProxyCh x;
	int resul = x.isProxy("208.91.197.104" , "80");
	std::cout << resul << std::endl;
	resul = x.isProxy("208.99.197.105" , "80");
	std::cout << resul << std::endl;
	return 0;
	}
