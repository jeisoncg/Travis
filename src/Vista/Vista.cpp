#include "Vista.hpp"

Vista::Vista(string db_name,string user,string pass,string host, string rutaArchivos, string rutaDiccionario){
	    	
	    if (!this->tormanager.isTorRunning()){
			cout<< color.BOLDRED << " [Warning]: " << color.RESET << " No se está ejecutando Tor" << endl ;
		}else{
			
			cout<< color.BOLDGREEN << " [OK]: " << color.RESET << " Está ejecutando Tor" << endl ;
			TorManager x;
			x.startHttpProxy("9050","8083");
			
		}
		this->rutaDiccionario = rutaDiccionario;
		lectura.Leer(rutaDiccionario);
		int tamano = lectura.getPalabras().size();
		this->rutaArchivos = rutaArchivos;
		this->conexion = new ConexionDB(db_name, user, pass, host);
		cout << color.BOLDGREEN << " [Conectado a]: " << color.RESET << host << " DB: " <<  db_name << endl;
		cout << color.BOLDBLUE << " [Ruta de los archivos]: " << color.RESET << rutaArchivos << endl;
		cout << color.BOLDBLUE << " [Ruta del diccionario] [Cantidad: " << tamano << "]: " << color.RESET << rutaDiccionario << endl;
		
	    Vista::menu();
	}
	
Vista::Vista()
{
	Vista::menu();
}
	
Vista::~Vista(){
	}

void Vista::menu(){
	
		cout<<endl;
		cout<<" Menú"<<endl<<endl;
		cout<<"1. Leer palabras desde archivo. (Están precargadas)"<<endl;
		cout<<"2. Mostrar palabras."<<endl;
		cout<<"3. Registrar palabras en la base de datos."<<endl;
		cout<<"4. Realizar consulta a la base de datos (Solo ejecuta)."<<endl;
		/*cout<<"5. Cargar Tor."<<endl;
		cout<<"6. Cargar Proxys"<<endl;
		cout<<"7. Mostrar lista de proxys cargados"<<endl;*/
		cout<<"5. Descargar lista de sinonimos."<<endl;
		cout<<"7. Mostrar sinonimos y antonimos de una palabra."<<endl;
		cout<<"8. Extraer sinonimos y antonimos del diccionario."<<endl;
		cout<<"9. Descargar lista de sinonimos (Caracter especial)"<<endl;
		cout<<endl;
		
		int seleccion = -1;
		
		
		bool seleccionNoValida = true;
		
		while(seleccionNoValida){
			
			cin >> seleccion;
			if ((seleccion > 0)&&(seleccion < 10)){
				
				
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
					if (seleccion == 7){
					Vista::extraer_una_palabra_sin_ant();
					}
					
				if (seleccion == 8){
					
					int i=0;
	
					int size =lectura.getPalabras().size();
					cout <<"Ingrese el numero de palabra desde la que desea iniciar: ";
					cin>> i;
					cout <<"Ingrese el numero de palabra desde la que desea finalizar, escriba 0 si quiere que sean todas: ";
					int tmp = 0;
					cin>> tmp;
					if (tmp != 0){
							size = tmp;
						}
					Vista::extraer_todas_relaciones_antonimos(i,size);
					}
				
				}
				
				if (seleccion == 9){
					
					cout <<"Caracteres especiales: ";
				
					Vista::descargar_palabras_caracter_expecial();
					
				
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
		vector <string> palabras_tmp = lectura.getPalabras();
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
void Vista::imprimir_relaciones_sinonimos()
{
	vector <Extraccion_Sinonimos::relac_sinonimo> lista_sinonimos;
	lista_sinonimos.clear();
	lista_sinonimos=una_extraccion->get_lista_sinonimos();
	int lista_sinonimos_size =lista_sinonimos.size();
	for(int i =0; i <lista_sinonimos_size; i++)
	{
		cout << lista_sinonimos[i].palabra1<<":"<<lista_sinonimos[i].palabra2<<endl;
	}
}
void Vista::imprimir_relaciones_antonimos()
{
	vector <Extraccion_Sinonimos::relac_antonimo> lista_antonimos;
	lista_antonimos.clear();
	lista_antonimos=una_extraccion->get_lista_antonimos();
	int lista_antonimos_size = lista_antonimos.size();
	for(int i =0; i <lista_antonimos_size; i++)
	{
		cout << lista_antonimos[i].palabra1<<":"<<lista_antonimos[i].palabra2<<endl;
	}
}
void Vista::extraer_una_palabra_sin_ant()
{
	cout<<endl;
	this->una_extraccion = new Extraccion_Sinonimos();
	string palabra ="";
	//cout<<"Ingrese la ruta de los archivos .html:";
	//cin>>ruta;
	cout<<"Ingrese la palabra: ";
	cin>>palabra;
	una_extraccion->extraer_sinonimos_antonimos(this->rutaArchivos,palabra);
	
	RelacionSinAnt relacion;
	relacion.setPalabra(palabra);
	relacion.setSinonimos(una_extraccion->getSinonimos());
	relacion.setAntonimos(una_extraccion->getAntonimos());
	relacion.print();
	
	/*cout << "--------Lista de sinonimos de "<<palabra<<"--------"<<endl;
	Vista::imprimir_relaciones_sinonimos();
	cout << "--------Lista de antonimos de "<<palabra<<"--------"<<endl;
	Vista::imprimir_relaciones_antonimos();*/
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

void Vista::descargar_palabras_caracter_expecial(void){
	ofstream filtro;
	filtro.open ("palabras_especiales.txt");
	int tmp_palabras = lectura.getPalabras().size();int entontradas = 0;
	for (int i = 0; i < tmp_palabras ; i++){

		
		bool flag = false;
		string tmp = lectura.getPalabras()[i];
		if ((tmp.find("ü") > 0) and (tmp.find("ü") < 50)){
			
				flag = true;
			
			}
		
		if (flag){
				entontradas++;
				cout << color.GREEN << " [SI] " <<color.RESET<< lectura.getPalabras()[i] << endl;
				filtro << tmp <<","<< "\n";
						
				
			}else{
						
				cout << " Encontradas: [" << entontradas << "]/["<<i<<"]" << color.RED<< " [NO] " <<color.RESET<< lectura.getPalabras()[i] << endl;
						
				}

	}
	
	filtro.close();

}
	  
void Vista::extraer_todas_relaciones_antonimos(int posInicial, int posFinal){
	
		string palabra ="";
		Extraccion_Sinonimos *extraccion  = new Extraccion_Sinonimos();
		
		for (int i = posInicial ; i < posFinal ;i++){
				
				RelacionSinAnt relacion;
				
				Extraccion_Sinonimos *extraccion  = new Extraccion_Sinonimos();
				extraccion->extraer_sinonimos_antonimos(this->rutaArchivos,"zrvz");
				extraccion->extraer_sinonimos_antonimos(this->rutaArchivos,lectura.getPalabras()[i]);
				
				relacion.setPalabra(lectura.getPalabras()[i]);
				relacion.setSinonimos(extraccion->getSinonimos());
				relacion.setAntonimos(extraccion->getAntonimos());
				
				//relacion.print();
				this->palabras_sinonimos_antonimos.push_back(relacion);
				std::cout << "[ " << i << " ]" << extraccion->getSinonimos().size() << " " << extraccion->getAntonimos().size() << std::endl;
				delete extraccion;
				
			}
		
		extraccion->RegistrarSinonimosBD(this->palabras_sinonimos_antonimos,this->conexion);
	
	
	}
	

