#include "Vista/Vista.cpp"
//#include "./Controladores/HTML_Reader.cpp"

int main(){

		
		Vista*  x = new Vista("Proyecto","root","root","localhost:3306", "/home/jeisoncg/FILES", "in.txt");
		
		//HTML_Reader x;
		//x.readFile("/home/jeisoncg/FILES_VERBOS/saltar.html");
		//x.loadPositions();
		
		/*x.getTag("<title>","</title>" );

		//std::vector <std::string> retorno = x.getTag("<div class=\"aa\">","</div>" );
		std::vector <std::string> retorno = x.getTag("<h4>","</h4>" );
		
		
		int tmp = retorno.size();
		
		
		for (int i = 0 ; i < tmp ; i++){
			
				std::cout << retorno[i] << "\n" << std::endl;
			}
		return 0;*/
	
	}
