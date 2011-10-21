/**
* @file
* @brief Interpreter is a module of miniSQL project.
* @author elf@ZJU
* @version 1.0
*
* transform the SQL into miniSQL inner functions
*/

#include "Interpreter.h"

/**
* @param void
* @exception none
* @return int
*/
int MyClass::fun(){
	return 0;
}

/**
* @param in an istream or an ifstream
* @exception all the DB errors
* @return void
* 
* Get a command from in(maybe multiple lines) ending with a ';'.
* Handle the SQL one character by one.
* //Transfer it to Interpreter module to handle.
*/
void HandleOneSQL(istream &in){
	string sql;				///< the string of a SQL command
	string line;			///< the string of a line
	bool inQuote = false;	///< in quote symbol

	// Get a command
	cout << "\nminiSQL> ";
	while(getline(in, line)){
		//inQuote = CheckLeftQuote(line);
		if(in != cin)
			cout << line << endl;
		sql += ' ' + line;
		if(line.find(';') != -1)
			break;
		cout << "      -> ";
	}

	//---------------------------------------------------------------------
	// Handle the SQL command
	switch(GetCmdType(sql)){
		case ExecFileType:
			//string fileName = "test.sql";
			ExecFile(string("test.sql"));
			break;
		case QuitType:
			throw ErQuit();
			break;
		default:
			cout << sql << endl;
	}
}

/**
* @param sql string &, the sql command
* @return CmdType, the command type enum
*
* determine the command type and return an enum
*/
CmdType GetCmdType(string &sql){
	if(sql.find("execfile") != -1){
		return ExecFileType;
	}
	else if(sql.find("quit") != -1){
		return QuitType;
	}
	else
		return CreateTableType;
}

/**
* @param fileName string &, the name of the SQL file
* @return void
*
* Execute the SQL commands from the file.
* If existing any exception, stop the execution.
*/
void ExecFile(string &fileName){
	ifstream fin(fileName.c_str());

	// if unable to open the file, throw an exception
	if(!fin){
		throw ErSQLFile();
	}

	while(!fin.eof()){
		HandleOneSQL(fin);
	}
	fin.close();
}