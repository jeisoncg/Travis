#include "Controladores/http.cpp"
#include <iomanip>
using std::setw;

int main (int argc, char *argv[])

{
	//http h;
    //h.descargar_sinonimos_completos();
    Proxy x;
    x.ping("www.google.com");
    cout<<x.ping("www.goosdgle.com");
	return 0;
}
