#include "http.hpp"
#include "Lectura.cpp"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

http::http()
{
	//this->encabezadoComando="GET www.wordreference.com/sinonimos/"; 
	this->encabezadoComando="aria2c http://www.wordreference.com/sinonimos/"; 
	this->extencionComando = ".html"; 
}

http::~http()
{
	
}
void http::construir_comando()
{
	this->comando= encabezadoComando + palabraComando + " -o " + palabraComando+extencionComando; //es la suma de los string anteriores para descargar la pagina con el comando GET 
}
void http::descargar_sinonimos_completos()
{
	Lectura lectura;
	lectura.Leer("in.txt");
	int i,  size = lectura.getPalabras().size();
	for(i = 0; i < size ; i++)
	{
		http::descargar_html(lectura.getPalabras().at(i));
	}
}
int http::descargar_html(string palabra)
{
	set_palabra(palabra);
	char cadena[6000]; //variable que recibe la linea leida del fstream
	



http::construir_comando();

 system(this->comando.c_str());
//~ printf("%s",final.c_str());

int contador =0;

   ifstream fe((palabraComando + ".html").c_str()); //se abre el fichero
  
    while(!fe.eof()) {
		contador++;
		fe.getline(cadena, 6000); 
		
			string tmp = cadena;
			if(contador==504)
			cout<<tmp<<endl;
    
    }
   fe.close();
   return 0;
}
void http::set_encabezado(string encabezado){
	this->encabezadoComando=encabezado;
}

void http::set_palabra(string palabra){
		this->palabraComando=palabra;
	}
	
void http::set_extencion(string extencion){
	this->extencionComando=extencion;
}

string http::getEncabezado()
{
	return this->encabezadoComando;
}

string http::get_palabra()
    {
		return this->palabraComando;
	}

string http::get_extencion(){
	return this->extencionComando;
}


