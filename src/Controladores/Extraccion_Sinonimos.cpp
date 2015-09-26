#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
struct relac_sinonimo {
   std::string palabra1; std::string palabra2;
};
struct relac_antonimo{
   std::string palabra1; std::string palabra2;
};
using namespace std;
vector <relac_sinonimo> lista_sinonimos;
vector <relac_antonimo> lista_antonimos;
void imprimir_relaciones()
{
	int lista_sinonimos_size = lista_sinonimos.size();
	for(int i =0; i <lista_sinonimos_size; i++)
	{
		cout << lista_sinonimos[i].palabra1<<":"<<lista_sinonimos[i].palabra2<<endl;
	}
}
void imprimir_relaciones_antonimos()
{
	int lista_antonimos_size = lista_antonimos.size();
	for(int i =0; i <lista_antonimos_size; i++)
	{
		cout << lista_antonimos[i].palabra1<<":"<<lista_antonimos[i].palabra2<<endl;
	}
}
int adicionar_relacion_sinonimos(string sinonimos, string palabra)
{
	
	relac_sinonimo relacion;
	relacion.palabra1=palabra;
	string aux="";
	int size = sinonimos.length();
	for(int i =0; i < size; i++)
	{
		switch(sinonimos.at(i)){
			case ',':relacion.palabra2=aux; aux="";lista_sinonimos.push_back(relacion); break;
			default:  aux=aux+sinonimos.at(i);break;
		}
		
	}
	imprimir_relaciones();
	return 0;
}
int adicionar_relacion_antonimos(string antonimos, string palabra)
{
	
	relac_antonimo relacion;
	relacion.palabra1=palabra;
	string aux="";
	int size = antonimos.length();
	for(int i =0; i < size; i++)
	{
		switch(antonimos.at(i)){
			case ',':relacion.palabra2=aux; aux="";lista_antonimos.push_back(relacion); break;
			default:  aux=aux+antonimos.at(i);break;
		}
		
	}
	imprimir_relaciones_antonimos();
	return 0;
}
int construir_antonimos(char *cadena, string palabra)
{
	
	string lista_antonimos="";
	int estado=0;
	int multiplicidad_de_palabras=0;
	for(int i =0; i<500000; i++)
	{
	 if(cadena[i] == 'E' && cadena[i+1] == 'S' && cadena[i+2] == 's')
		 {
			 cout << multiplicidad_de_palabras<<endl;
						 multiplicidad_de_palabras++;
						 if(multiplicidad_de_palabras==2)
						 {
							i=500000;
							
						 }
		 }	
	 
	
	if(cadena[i] == 'm'&& cadena[i+1] == 'o' && cadena[i+2] == 's'&& cadena[i+3] == ':' )
	{
		
		estado = 1 ;
		i=i+5;
	}
	if(cadena[i] == '<'&& cadena[i+1] == '/' && cadena[i+2] == 'l'&& cadena[i+3] == 'i'&& cadena[i+4] == '>')
	{				
		estado = 0;
		if(lista_antonimos.length()>1)
		{
		if(lista_antonimos.at(lista_antonimos.length()-1) != ',')
		{
		lista_antonimos+=",";
	    }
	    }
	}
	if(estado==1 && cadena[i]!=' ')
	{
		lista_antonimos+=cadena[i];
	}
	
}
    cout <<lista_antonimos<<endl;
    adicionar_relacion_antonimos(lista_antonimos,palabra);
	return 0;
}


int construir_sinonimos(char *cadena, string palabra)
{
	string lista_sinonimos="";
	int estado=0;
	int multiplicidad_de_palabras=0;
	for(int i =0; i<500000; i++)
	{
	 if(cadena[i] == 'E' && cadena[i+1] == 'S' && cadena[i+2] == 's')
		 {
			 cout << multiplicidad_de_palabras<<endl;
						 multiplicidad_de_palabras++;
						 if(multiplicidad_de_palabras==2)
						 {
							i=500000;
						 }
		 }	
	 
	
	if(cadena[i] == '<'&& cadena[i+1] == 'l' && cadena[i+2] == 'i'&& cadena[i+3] == '>' &&cadena[i+4] != '<')
	{
		estado = 1 ;
		i=i+4;
	}
	if(cadena[i] == '<'&& cadena[i+1] == '/' && cadena[i+2] == 'l'&& cadena[i+3] == 'i'&& cadena[i+4] == '>')
	{
		
		if(lista_sinonimos.at(lista_sinonimos.length()-1) != ',')
		{
		lista_sinonimos+=",";
	    }
		estado = 0;
	}
	if(estado==1&&cadena[i]!=' ')
	{
		lista_sinonimos+=cadena[i];
	}
}
    cout <<lista_sinonimos<<endl;
    adicionar_relacion_sinonimos(lista_sinonimos,palabra);
	return 0;
}
int main (int args, char **argv)
{
	
	cout << "hola mundo!"<<endl;
	
	char cadena[500000];
    ifstream fe;
    string palabra="bien";
    string direccion="/home/lusho/TravisTMP/"+palabra+".html";
    fe.open(direccion.c_str());
    while(fe.getline(cadena, 500000))
    {
     for(int j = 0; j<500000; j++)
     {
		 if(cadena[j] == 'E' && cadena[j+1] == 'S' && cadena[j+2] == 's')
		 {
		 construir_sinonimos(cadena,palabra);
		 construir_antonimos(cadena,palabra);
		return 0 ;
	     }
	 }
    }
   
	return 0;
}
