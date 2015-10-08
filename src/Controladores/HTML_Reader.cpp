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
