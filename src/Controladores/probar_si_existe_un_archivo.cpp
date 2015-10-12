#include <fstream>
#include <iostream>
#include <string>
#include "Lectura.cpp"
using namespace std;
int main(int args, char **argv)
{
	
	Lectura una_lectura;
	
	int numero_lineas, size=0; 
	size++;
	vector <string> palabras_faltantes;
	FILE * pFile;
	string directorio_principal,palabra,file,extencion;
    ofstream archivo_salida("/home/lusho/Escritorio/palabras_faltantes.txt");;
     char buffer[5000];
  	cout<<"ingrese el directorio donde estan los .html (con un / al final)"<<endl;
	cin>>directorio_principal;
	extencion=".html";
	una_lectura.Leer("/home/lusho/Travis/src/in.txt");
    cout<<"se han leido "<<una_lectura.getPalabras().size()<<" palabras"<<endl;

  

    size=una_lectura.getPalabras().size();
    for(int i =0; i<40031;i++)
    {
		int esta=-1;
		esta=una_lectura.getPalabras().at(i).find("ü");
		if(esta==-1)
		{
		numero_lineas=0;
   file=directorio_principal+una_lectura.getPalabras().at(i)+extencion;
   pFile = fopen (file.c_str() , "r");
   if (pFile == NULL)
   {
	  
	   palabras_faltantes.push_back(una_lectura.getPalabras().at(i));
	   cout<<"la palabra "<< una_lectura.getPalabras().at(i)<<" falta"<<endl;
	   archivo_salida<<una_lectura.getPalabras().at(i)<<endl;
	}
		
		else
		{
		
			 while ( ! feof (pFile) and !(numero_lineas > 251))
     {
		  if ( fgets (buffer , 5000 , pFile) == NULL ) break;
       numero_lineas++;
     }
				fclose (pFile);
				
				if(numero_lineas<251)
				{
		
		palabras_faltantes.push_back(una_lectura.getPalabras().at(i));
	   cout<<"la palabra "<< una_lectura.getPalabras().at(i)<<" falta"<<endl;
	   archivo_salida<<una_lectura.getPalabras().at(i)<<endl;		
                }
		}
   }
    archivo_salida.close();
}
   return 0;
}
