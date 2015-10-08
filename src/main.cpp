#include "Vista/Vista.cpp"
#include "./Controladores/HTML_Reader.cpp"

int main(){
		
		
		Vista*  x = new Vista("jarvis","root","root","localhost:3306", "/home/jeisoncg/FILES", "in.txt");
		x->menu();
		/*
		HTML_Reader dx;
		dx.readFile("/home/jeisoncg/correr.html");
		//x.getTag("<title>","</title>" );
		
		
		
		
		std::vector <std::string> retorno = dx.getTag("<div class=\"aa\">","</div>" );
		
		
		int tmp = retorno.size();
		
		
		for (int i = 0 ; i < tmp ; i++){
			
				std::cout << retorno[i] << "\n" << std::endl;
			}*/
		return 0;
	
	}
