#include "Vista.hpp"

Vista::Vista(){
	
		cout<<"...Datos de Conexión a la Base de Datos..."<<endl<<endl;
		cout<<"Host BD: ";
		string host;
		cin >> host;
		cout<<"Nombre BD: ";
		string db_name;
		cin >> db_name;
		cout<<"Usuario: ";
		string user;
		cin >> user;
		cout<<"Password: ";
		string pass;
		cin >> pass;
		system("clear");
		
		this->conexion = new ConexionDB(db_name, user, pass, host);
	
	}
	
Vista::~Vista(){}

void Vista::menu(){
	
		cout<<"Menú"<<endl<<endl;
		cout<<"1. Leer palabras desde archivo."<<endl;
		cout<<"2. Mostrar palabras."<<endl;
		cout<<"3. Registrar palabras en la base de datos."<<endl;
		cout<<"4. Realizar consulta a la base de datos (Solo ejecuta)."<<endl;
		cout<<"5. Salir."<<endl<<endl;
		
		int seleccion = -1;
		
		
		bool seleccionNoValida = true;
		
		while(seleccionNoValida){
			
			cin >> seleccion;
			if ((seleccion > 0)&&(seleccion < 5)){
				
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
				if (seleccion == 5){}
				
				
				}else{
					system("clear");
					menu();
					
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
