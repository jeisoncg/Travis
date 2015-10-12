#ifndef http_hpp
#define http_hpp

#include <string>
#include <vector>


using std::vector;

class http{
	
	private:
	
	std::string encabezadoComando; //indica la pagina principal de la que extraera la informacion
	std::string palabraComando; //indica la palabra a consultar
	std::string extencionComando; //indica la extencion de la pagina (html, php, aspx...)
	std::string comando;//es la suma de los argumentos y el comando, el cual se ejecutara en system
	std::string proxy_actual; //es el proxy el cual se esta utilizando en el comando aria2c
	

   
	
	
	public:
	http();
	~http();
	void set_encabezado(std::string encabezado);
    void set_palabra(std::string palabra);
    void set_extencion(std::string extencion);
    void set_proxy_actual(std::string nuevo_proxy);
    std::string getEncabezado();
    std::string get_palabra();
    std::string get_extencion();
    std::string get_comando();
    std::string get_proxy_actual();
	int descargar_html(std::string palabra);
	void descargar_sinonimos_completos();
	void construir_comando(); //construlle el comando con base en el encabezado, la palabra a consulatar y la extencion
	
};


#endif

