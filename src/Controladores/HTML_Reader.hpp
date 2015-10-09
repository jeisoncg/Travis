#ifndef HTML_Reader_hpp_
#define HTML_Reader_hpp_

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class HTML_Reader {

		private:
			
			std::string route;
			std::vector <std::string> document_html;
			/**
			 * 	Esta variable ayuda en el proceso de recursividad
			 * 	estableciendo la posición en el vector document_html
			 * 	donde se debe empezar a analizar.
			 * 
			 * **/
			int vector_position;
			/**
			 * 	Esta variable ayuda en el proceso de recursividad
			 * 	almacenando el retorno de la función getTag(...)
			 *  de manera temporal.
			 * 
			 * **/
			std::vector <std::string> recursive_vector;
		
			/**
			 * 	Este metodo permite la extracción de toda una etiqueta encontrada en el documento.
			 * 	
			 * 	Entradas: tag_Open, tag_Close.
			 * 
			 * 	tag_Open: Es el inicio de la etiqueta, por ejemeplo "<script>"
			 * 	tag_Close: Es el final de la etiqueta, por ejemeplo "</script>"
			 * 
			 * 	Este metodo extrae el o los fragmentos de texto presentes entre estas dos 
			 * 	etiquetas, cade destacar que extrae hasta inmediatamente la primer etiqueta de
			 * 	corte que sea encontrada.
			 * 
			 * 	Ejemplo: getTag("<div id= "Ejemplo">", </div>)
			 * 	
			 * 	Tomemos esto como documento html previamente cargado: <html> <script> Prueba </script> </script> </hmtl>
			 * 	El resultado de esa ejecución arrojará: <script> Prueba </script>.
			 * 
			 * 	En caso de haber multiples definiciones de las etiquetas: <html> <script> Prueba </script> <script></script> </hmtl>
			 * 
			 * 	Tendremos como resultado un vector de esta forma:
			 * 	Pos(0): <script> Prueba </script>
			 * 	Pos(1): <script></script>
			 * 
			 * **/
			void getTagx(std::string tag_Open, std::string tag_Close); 
			std::vector <std::string> getTag(std::string tag_Open, std::string tag_Close);
			
			int indicativo_POS[2];
			int tiempos_Compuestos_Comunes_POS[2];
			int subjuntivo_POS[2];
			int tiempos_Compuestos_Subjuntivo_POS[2];
			int Imperativo_POS[2];
			int indicativo_preterito_anterior_POS[2];
			
			std::vector <std::string> conjugaciones_sin_procesar;
			
		public:
			HTML_Reader();
			~HTML_Reader();
			
			void loadPositions(void);
			
			void readFile(std::string route);
			
			
	
	};

#endif
