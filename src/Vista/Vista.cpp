#include "Vista.hpp"

Vista::Vista(){
	    	
	    if (!this->tormanager.isTorRunning()){
			cout<< color.BOLDRED << " [Warning]: " << color.RESET << " No se está ejecutando Tor" << endl << endl;
		}else{
			
			cout<< color.BOLDGREEN << " [OK]: " << color.RESET << " Está ejecutando Tor" << endl << endl;
			TorManager x;
			x.startHttpProxy("9050","8083");
			
		}
		
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
	
		cout<<endl;
		cout<<"Menú"<<endl<<endl;
		cout<<"1. Leer palabras desde archivo."<<endl;
		cout<<"2. Mostrar palabras."<<endl;
		cout<<"3. Registrar palabras en la base de datos."<<endl;
		cout<<"4. Realizar consulta a la base de datos (Solo ejecuta)."<<endl;
		/*cout<<"5. Cargar Tor."<<endl;
		cout<<"6. Cargar Proxys"<<endl;
		cout<<"7. Mostrar lista de proxys cargados"<<endl;*/
		cout<<"5. Descargar lista de sinonimos"<<endl;
		cout<<"6. Salir."<<endl<<endl;
		
		int seleccion = -1;
		
		
		bool seleccionNoValida = true;
		
		while(seleccionNoValida){
			
			cin >> seleccion;
			if ((seleccion > 0)&&(seleccion < 7)){
				
				
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
				/*if (seleccion == 5){
					cout<<"Cargando tor\n ";
					system("tor &");
					}
				if (seleccion == 6){
					cout<<"Ruta del archivo con los Proxys: ";
					Vista::cargar_proxis();
					}
				if (seleccion == 7){
					cout<<"Lista de proxys:"<<endl;
					Vista::mostrar_lista_proxis();
					}*/
				if (seleccion == 5){
					cout<<"Descargando informacion sinomial:"<<endl;
					Vista::descargar_todos_sinonimos();
					}
					
				if (seleccion == 6){
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
		//int j=0;
		
		int size =lectura.getPalabras().size();
		cout <<"Ingrese el numero de palabra desde la que desea iniciar: ";
		cin>> i;
		cout <<"Ingrese el numero de palabra desde la que desea finalizar, escriba -1 si quiere que sean todas: ";
		int tmp = 0;
		cin>> tmp;
		if (tmp != -1){
				size = tmp;
			}
		iaux=i;
		
      for(; i<size;i++)
      {
	  if(((i-iaux)%500)==0)
	  {
		  /*for(int k=0; k<proxy.get_TotalProxiesAlmacenados(); k++)
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
			}*/
			
			descargas.descargar_html(lectura.getPalabras().at(i));
			tormanager.get_New_Tot_IP_Address();
			cout<<color.BOLDGREEN<<"Cambio de IP"<<color.RESET<<endl;
	  }	 
	  
	  
	 else{
		  cout<<descargas.get_proxy_actual()<<endl;
		  descargas.descargar_html(lectura.getPalabras().at(i));
	 }
  }
	 
	  
     
	
}
