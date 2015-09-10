#ifndef http_hpp
#define http_hpp

#include <string>
#include <vector>
#include "Proxy.cpp"

using std::vector;

class http{
	
	private:
	
	std::string encabezadoComando; //indica la pagina principal de la que extraera la informacion
	std::string palabraComando; //indica la palabra a consultar
	std::string extencionComando; //indica la extencion de la pagina (html, php, aspx...)
	std::string comando;
	Proxy *proxies;

	
	
	public:
	void cargar_archivo();
	void set_encabezado(std::string encabezado);
    void set_palabra(std::string palabra);
    void set_extencion(std::string extencion);
    std::string getEncabezado();
    std::string get_palabra();
    std::string get_extencion();
	http(Proxy *proxies);
	~http();
	int descargar_html(std::string palabra,std::string proxyURL);
	void descargar_sinonimos_completos();
	void construir_comando(std::string proxyURL); //construlle el comando con base en el encabezado, la palabra a consulatar y la extencion
	
};


#endif
