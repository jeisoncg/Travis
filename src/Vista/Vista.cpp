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
		cout<<"5. Cargar Proxys"<<endl;
		cout<<"6. Mostrar lista de proxys cargados"<<endl;
		cout<<"7. Descargar lista de sinonimos"<<endl;
		cout<<"8. Salir."<<endl<<endl;
		
		int seleccion = -1;
		
		
		bool seleccionNoValida = true;
		
		while(seleccionNoValida){
			
			cin >> seleccion;
			if ((seleccion > 0)&&(seleccion < 9)){
				
				
				if (seleccion == 1){
					Vista::leerPalabras();
					
					}
				if (seleccion == 2){
					Vista::mostrarPalabras();
					
					}
				if (seleccion == 3){
						
						Vista::registrarPalabras();
						
					}
				if (seleccion == 4){
					
					cout<<"Consulta: ";
					cin.clear();
					cin.sync();
					cin.ignore();
					string consulta;
					getline(cin, consulta);	
					Vista::realizarConsulta(consulta);
					
					}
				if (seleccion == 5){
					cout<<"Ruta del archivo con los Proxys: ";
					Vista::cargar_proxis();
					}
				if (seleccion == 6){
					cout<<"Lista de proxys:"<<endl;
					Vista::mostrar_lista_proxis();
					}
				if (seleccion == 7){
					cout<<"Descargando informacion sinomial:"<<endl;
					Vista::descargar_todos_sinonimos();
					}
					
				if (seleccion == 8){
					return;
					}
				
				}
			
		};
		
	}
	
void Vista::cargar_proxis(){
	
	    string ruta_proxys;
	    cin >> ruta_proxys;
	    cout<<endl;
	    this->proxy.set_ProxyUrlDesdeArchivo(ruta_proxys);
	    menu();
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
	menu();
}

void Vista::descargar_todos_sinonimos()
{
		int i=0;
		int iaux=0;
		int j=0;
		
		int size =lectura.getPalabras().size();
		cout <<"Ingrese el numero de palabra desde la que desea iniciar: ";
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
