#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include "Extraccion_Sinonimos.hpp"

using namespace std;
Extraccion_Sinonimos::Extraccion_Sinonimos()
{
	
}
Extraccion_Sinonimos::~Extraccion_Sinonimos()
{
	
}


int Extraccion_Sinonimos::adicionar_relacion_sinonimos(string sinonimos, string palabra)
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

	return 0;
}
int Extraccion_Sinonimos::adicionar_relacion_antonimos(string antonimos, string palabra)
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
	return 0;
}
int Extraccion_Sinonimos::construir_antonimos(char *cadena, string palabra)
{
	
	string lista_antonimos="";
	int estado=0;
	int multiplicidad_de_palabras=0;
	for(int i =0; i<500000; i++)
	{
	 if(cadena[i] == 'E' && cadena[i+1] == 'S' && cadena[i+2] == 's')
		 {
			
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

    Extraccion_Sinonimos::adicionar_relacion_antonimos(lista_antonimos,palabra);
	return 0;
}


int Extraccion_Sinonimos::construir_sinonimos(char *cadena, string palabra)
{
	string lista_sinonimos="";
	int estado=0;
	int multiplicidad_de_palabras=0;
	for(int i =0; i<500000; i++)
	{
	 if(cadena[i] == 'E' && cadena[i+1] == 'S' && cadena[i+2] == 's')
		 {
		
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
    Extraccion_Sinonimos::adicionar_relacion_sinonimos(lista_sinonimos,palabra);
	return 0;
}
vector <Extraccion_Sinonimos::relac_sinonimo> Extraccion_Sinonimos::get_lista_sinonimos()
{
	return this->lista_sinonimos;
}

vector <Extraccion_Sinonimos::relac_antonimo> Extraccion_Sinonimos::get_lista_antonimos()
{
	return this->lista_antonimos;
}


int Extraccion_Sinonimos::extraer_sinonimos_antonimos(string ruta, string palabra)
{
	
	
	
	char cadena[500000];
    ifstream fe;
    string direccion=ruta+"/"+palabra+".html";
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
