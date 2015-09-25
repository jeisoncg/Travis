#include "ConexionBD.hpp"
ConexionDB::ConexionDB(){}
ConexionDB::ConexionDB(string db_name, string user, string password, string host){
	
		this->DB_host = host;
		this->DB_user = user;
		this->DB_password = password;
		this->DB_name = db_name;
		
		this->driver = get_driver_instance();
		this->con = driver->connect("tcp://" + this->DB_host,this->DB_user, this->DB_password);
		this->con->setSchema(this->DB_name);
	
	}
ConexionDB::~ConexionDB(){}

void ConexionDB::ejecutarConsulta(string consulta){
	
		try {
	
			//prep_stmt = con->prepareStatement(consulta);
			//prep_stmt->execute(consulta.c_str());
			//delete prep_stmt;
			
			stmt = con->createStatement();
			res = stmt->executeQuery(consulta.c_str());
			
			//cout<<"Ejecutado: " + consulta <<endl;

		} catch (sql::SQLException e) {
			string error = "";
			error = e.what();
			if( error != ""){
				cout<<e.what()<<endl;
			}
			
		}
	
	}
	
string ConexionDB::getDB_host(){return this->DB_host;};
string ConexionDB::getDB_user(){return this->DB_user;};
string ConexionDB::getDB_password(){return this->DB_password;};
string ConexionDB::getDB_name(){return this->DB_name;};
