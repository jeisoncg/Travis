#include "HTML_Reader.hpp"

HTML_Reader::HTML_Reader(){
	
		this->vector_position = 0;
	
	}
HTML_Reader::~HTML_Reader(){}

void HTML_Reader::readFile(std::string route){
		
		this->route = route;
		this->document_html.clear();
		std::ifstream input(route.c_str());
		
		while(!input.eof()) 
		{
			char chain[50000];
			input.getline(chain, 50000);
			this->document_html.push_back(chain);
			//std::cout << chain << std::endl; // Impresión de la entrada.
			
			};
	
	}

// Documentación en el hpp
void HTML_Reader::getTagx(std::string tag_Open, std::string tag_Close){
		
		std::vector <std::string> returnx = this->recursive_vector;
		
		std::vector <std::string > document_html;
		
		int document_html_size_class = this->document_html.size();
		for (int i = this->vector_position ; i < document_html_size_class ; i++){
			
				document_html.push_back(this->document_html[i]);
			
			}
			
		int document_html_size = document_html.size();
		
		bool tag_Open_found = false;
		bool tag_Close_found = false;
		int position_initial_character_tag_open = -1;
		int position_initial_vector = -1;
		int position_final_vector = -1;
		
		for (int i = 0 ; i < document_html_size ; i++){
			
				std::string tmp_string = document_html[i];
				
				if ( ((tmp_string.find(tag_Open)) >= 0) and ((tmp_string.find(tag_Open)) <= 50000) and (!tag_Open_found) ){
						
						tag_Open_found = true;
						position_initial_character_tag_open = tmp_string.find(tag_Open);
						position_initial_vector = i;
					}
					
				if ( ((tmp_string.find(tag_Close)) >= 0) and ((tmp_string.find(tag_Close)) <= 50000) and (!tag_Close_found) and (tag_Open_found)){
						
						tag_Close_found = true;
						position_final_vector = i;
						break;
					}
			
			}
			
		//std::cout << position_initial_vector << " - " << position_final_vector << std::endl; 
			
		this->vector_position += position_final_vector; // Solo para WordReference, sección Conjugados de verbos.
		if (position_initial_vector == -1){
			
				this->vector_position = 0;

			}
			
		//std::cout << this->vector_position << std::endl;
		std::string return_chain = "";
		int return_chain_close = 0;
		std::string clean_chain = "";
		bool flag_start_save = false;
		
		if (position_initial_vector == position_final_vector){
			
				return_chain +=  document_html[position_initial_vector];
				
				return_chain_close = return_chain.find(tag_Close);
				for (int x = position_initial_character_tag_open; x < return_chain_close; x++){
						
							if ((return_chain[x] == '>') and (!flag_start_save)){
									x++;
									flag_start_save = true;
									
								}
							
							if (flag_start_save){
								
									clean_chain += return_chain[x];
								
								}
							
						}
			
			}else{
		
					for (int i = position_initial_vector; i < position_final_vector + 1 ; i++ ){
							
							return_chain +=  document_html[i];
			
						}
					
					return_chain_close = return_chain.find(tag_Close);
					
					for (int x = position_initial_character_tag_open; x < return_chain_close; x++){
						
							if ((return_chain[x] == '>') and (!flag_start_save)){
									x++;
									flag_start_save = true;
									
								}
							
							if (flag_start_save){
								
									clean_chain += return_chain[x];
								
								}
							
						}
			
		}
		
		//std::cout << clean_chain << std::endl;	
		
		this->recursive_vector.push_back(clean_chain);
		HTML_Reader::getTag(tag_Open, tag_Close);

	}

std::vector <std::string> HTML_Reader::getTag(std::string tag_Open, std::string tag_Close){
		HTML_Reader::getTagx(tag_Open, tag_Open);
		return this->recursive_vector;
	
	}
	
void HTML_Reader::loadPositions(void){
	
		std::string chain = "<div class=\"aa\">";
		std::string chainEnd = "</div>";
		std::vector <int> pos_ClassAA;
		std::vector <int> pos_ClassAAEND;
		int document_html_size = this->document_html.size();
		for (int i = 0; i < document_html_size; i++){
			
				if ( ((this->document_html[i].find(chain)) >= 0) and ((this->document_html[i].find(chain)) <= 50000)  ){
						
						pos_ClassAA.push_back(i);
						//std::cout << "AA " << i << std::endl;
					}
			
			}
		int contador = 0;
		for (int i = pos_ClassAA[0]; i < document_html_size; i++){
				
				if (contador == 6){
					
						break;
					
					}
				
				if ( ((this->document_html[i].find(chainEnd)) >= 0) and ((this->document_html[i].find(chainEnd)) <= 50000)  ){
						
						pos_ClassAAEND.push_back(i);
						contador++;
						//std::cout << "EE " << i << std::endl;
					}
				
			}
		
		this->indicativo_POS[0] = pos_ClassAA[0];
		this->tiempos_Compuestos_Comunes_POS[0]= pos_ClassAA[1];
		this->subjuntivo_POS[0]= pos_ClassAA[2];
		this->tiempos_Compuestos_Subjuntivo_POS[0]= pos_ClassAA[3];
		this->Imperativo_POS[0]= pos_ClassAA[4];
		this->indicativo_preterito_anterior_POS[0]= pos_ClassAA[5];
		
		this->indicativo_POS[1] = pos_ClassAAEND[0];
		this->tiempos_Compuestos_Comunes_POS[1]= pos_ClassAAEND[1];
		this->subjuntivo_POS[1]= pos_ClassAAEND[2];
		this->tiempos_Compuestos_Subjuntivo_POS[1]= pos_ClassAAEND[3];
		this->Imperativo_POS[1]= pos_ClassAAEND[4];
		this->indicativo_preterito_anterior_POS[1]= pos_ClassAAEND[5];
		
		//std::cout << indicativo_preterito_anterior_POS[0] << " - " << indicativo_preterito_anterior_POS[1] << std::endl;
		
		//-------------------------------------------------------------------------------------------------------------
		std::string chain_tmp = "";
		this->conjugaciones_sin_procesar.push_back("");
		for (int i = this->indicativo_POS[0] ; i < this->indicativo_POS[1]+1; i++){
				this->conjugaciones_sin_procesar[0] += this->document_html[i];
				std::cout << " ---> " << this->document_html[i] << "\n" << std::endl;
			}
		//this->conjugaciones_sin_procesar.push_back(chain_tmp);
		chain_tmp = "";
		for (int i = this->tiempos_Compuestos_Comunes_POS[0] ; i < this->tiempos_Compuestos_Comunes_POS[1]+1; i++){
				chain_tmp += this->document_html[i];
			}
		this->conjugaciones_sin_procesar.push_back(chain_tmp);
		chain_tmp = "";
		for (int i = this->subjuntivo_POS[0] ; i < this->subjuntivo_POS[1]+1; i++){
				chain_tmp += this->document_html[i];
			}
		this->conjugaciones_sin_procesar.push_back(chain_tmp);
		chain_tmp = "";
		for (int i = this->tiempos_Compuestos_Subjuntivo_POS[0] ; i < this->tiempos_Compuestos_Subjuntivo_POS[1]+1; i++){
				chain_tmp += this->document_html[i];
			}
		this->conjugaciones_sin_procesar.push_back(chain_tmp);
		chain_tmp = "";
		for (int i = this->Imperativo_POS[0] ; i < this->Imperativo_POS[1]+1; i++){
				chain_tmp += this->document_html[i];
			}
		this->conjugaciones_sin_procesar.push_back(chain_tmp);
		chain_tmp = "";
		for (int i = this->indicativo_preterito_anterior_POS[0] ; i < this->indicativo_preterito_anterior_POS[1]+1; i++){
				chain_tmp += this->document_html[i];
			}
		this->conjugaciones_sin_procesar.push_back(chain_tmp);
		chain_tmp = "";
		
		/*int conjugaciones_sin_procesar_size = this->conjugaciones_sin_procesar.size();
		for (int i = 0 ; i < conjugaciones_sin_procesar_size ; i++){*/
			
				std::cout << " ---> " << this->conjugaciones_sin_procesar[0] << "\n" << std::endl;
			
			/*}*/
		
	}
