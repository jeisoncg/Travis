#ifndef ConexionDB_hpp
#define ConexionDB_hpp

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdlib.h>

#include <mysql_connection.h>
#include <mysql_driver.h>

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

using namespace std;
using std::vector;
using std::string;

	class ConexionDB{
		
		private:
		
			string DB_host;
			string DB_user;
			string DB_password;
			string DB_name;
			
			sql::Driver *driver;
			sql::Connection *con;
			sql::Statement *stmt;
			sql::ResultSet *res;
			sql::PreparedStatement  *prep_stmt;
			
		
		public:
			ConexionDB();
			ConexionDB(string db_name, string user, string password, string host);
			~ConexionDB();
			string getDB_host();
			string getDB_user();
			string getDB_password();
			string getDB_name();
			void ejecutarConsulta(string consulta);
		
		
	};

#endif
