#include "Vista.hpp"

Vista::Vista(){
	
	    
	    
		//~ cout<<"...Datos de Conexión a la Base de Datos..."<<endl<<endl;
		//~ cout<<"Host BD: ";
		//~ string host;
		//~ cin >> host;
		//~ cout<<"Nombre BD: ";
		//~ string db_name;
		//~ cin >> db_name;
		//~ cout<<"Usuario: ";
		//~ string user;
		//~ cin >> user;
		//~ cout<<"Password: ";
		//~ string pass;
		//~ cin >> pass;
		//~ system("clear");
		//~ 
		//~ this->conexion = new ConexionDB(db_name, user, pass, host);
	    Vista::menu();
	}
	
Vista::~Vista(){}

void Vista::menu(){
	
		cout<<"Menú"<<endl<<endl;
		cout<<"1. Leer palabras desde archivo."<<endl;
		cout<<"2. Mostrar palabras."<<endl;
		cout<<"3. Registrar palabras en la base de datos."<<endl;
		cout<<"4. Realizar consulta a la base de datos (Solo ejecuta)."<<endl;
		cout<<"5. Mostrar lista de proxys cargados"<<endl;
		cout<<"6. Descargar lista de sinonimos"<<endl;
		cout<<"7. Salir."<<endl<<endl;
		
		int seleccion = -1;
		
		
		bool seleccionNoValida = true;
		
		while(seleccionNoValida){
			
			cin >> seleccion;
			if ((seleccion > 0)&&(seleccion < 7)){
				
				seleccionNoValida = false;
				
				if (seleccion == 1){
					leerPalabras();
					
					}
				if (seleccion == 2){
					mostrarPalabras();
					
					}
				if (seleccion == 3){
						
						registrarPalabras();
						
					}
				if (seleccion == 4){
					
					cout<<"Consulta: ";
					cin.clear();
					cin.sync();
					cin.ignore();
					string consulta;
					getline(cin, consulta);	
					realizarConsulta(consulta);
					
					}
				if (seleccion == 5){
					cout<<"Lista de proxys:"<<endl;
					mostrar_lista_proxis();
					}
				if (seleccion == 6){
					cout<<"Descargando informacion sinomial:"<<endl;
					Vista::descargar_todos_sinonimos();
					}
				
				}
			
		};
		
	}
	
void Vista::leerPalabras(){
	
		system("clear");
		cout << "Ruta: ";
		string ruta;
		cin>>ruta;
		
		lectura.Leer(ruta);
		int tamano = lectura.getPalabras().size();
		cout << "Cantidad:" + static_cast<ostringstream*>(&(ostringstream() << tamano))->str() << endl;
		menu();
	
	}
void Vista::mostrarPalabras(){
	
		lectura.MostrarPalabras();
		
		menu();
	
	}
void Vista::realizarConsulta(string consulta){
		this->conexion->ejecutarConsulta(consulta);
		menu();
	}
	
void Vista::registrarPalabras(){
	
		lectura.RegistrarPalabrasBD(lectura.getPalabras(),this->conexion);
		menu();
	}
void Vista::mostrar_lista_proxis()
{
	int size = this->proxy.get_TotalProxiesAlmacenados();
	for(int i = 0 ; i<size;i++)
	{
		cout << proxy.get_ProxyUrl(i)<<endl;
	}
}

void Vista::descargar_todos_sinonimos()
{
	int i=0;
	int iaux=0;
    int j=0;
cout<<"Ingrese la ruta del archivo contenedor de los proxys:"<<endl;

	    string ruta_proxys;
	    cin >> ruta_proxys;
	    this->proxy.set_ProxyUrlDesdeArchivo(ruta_proxys);
      int size =lectura.getPalabras().size();
cout <<"Ingrese el numero de palabra desde la que desea iniciar:"<<endl;
cin>> i;
iaux=i;
      for(; i<size;i++)
      {
	  if(((i-iaux)%700)==0)
	  {
		  for(int k=0; k<proxy.get_TotalProxiesAlmacenados(); k++)
		  {
				if(proxy.ping(proxy.retornar_url_sin_puerto(proxy.get_ProxyUrl(j)))==0)
					{
					descargas.set_proxy_actual(this->proxy.get_ProxyUrl(j));
					descargas.descargar_html(lectura.getPalabras().at(i));
					j++;
					k=proxy.get_TotalProxiesAlmacenados();
						}
				else{
				    j++;
					}
	  }
	  }	  
	  
	 else{
		  cout<<descargas.get_proxy_actual()<<endl;
		  descargas.descargar_html(lectura.getPalabras().at(i));
	 }
  }
	 
	  
     
	
}
