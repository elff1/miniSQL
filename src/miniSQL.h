/**
* @file
* @brief the head file of the miniSQL
* @author elf@ZJU
* @version 1.0
*
* ...
*/

#ifndef _miniSQL_H
#define _miniSQL_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cstring>

using namespace std;

/** @def define the most numbers of attribute*/
#define MaxAttri 32
/** @def define the most length of string*/
#define MaxStrLen 255
/** @def define the most length of identifier name*/
#define MaxIdentLen 50

/**
* @class DbEr
* @brief the base exception class of miniSQL//, inheriting from the exception
*/
class DbEr{// : public exception{
protected:
	char *info;
public:
	DbEr(){info = NULL;};
	char *what(){return info;}
};

/**
* @class ErCreateFile
* @brief the create file exception
*/
class ErCreateFile : public DbEr{
public:
	ErCreateFile(char *str = "Can't create file "){info = str;}
};

/**
* @class ErCreateTable
* @brief the create table exception
*/
class ErCreateTable : public DbEr{
public:
	ErCreateTable(char *str = "Can't create table "){info = str;}
};

/**
* @class ErDeleteFile
* @brief the delete file exception
*/
class ErDeleteFile : public DbEr{
public:
	ErDeleteFile(char *str = "Can't delete file "){info = str;}
};

/**
* @class ErOpenFile
* @brief the open file exception
*/
class ErOpenFile : public DbEr{
public:
	ErOpenFile(char *str = "Can't open file"){info = str;}
};

/**
* @class ErWriteFile
* @brief the write file exception
*/
class ErWriteFile : public DbEr{
public:
	ErWriteFile(char *str = "Can't write file"){info = str;}
};

/**
* @class ErKeyNotFound
* @brief the record not found exception
*/
class ErKeyNotFound : public DbEr{
public:
	ErKeyNotFound(char *str = "Can't find record in "){info = str;}
};

/**
* @class ErUnknownCom
* @brief the unknown command exception
*/
class ErUnknownCom : public DbEr{
public:
	ErUnknownCom(char *str = "Unknown command"){info = str;}
};

/**
* @class ErBadNull
* @brief the bad null column exception
*/
class ErBadNull : public DbEr{
public:
	ErBadNull(char *str = "Can't be null of column "){info = str;}
};

/**
* @class ErTableExists
* @brief the table existing exception
*/
class ErTableExists : public DbEr{
public:
	ErTableExists(char *str = "The table exists"){info = str;}
};

/**
* @class ErUnknownTable
* @brief the unknown table exception
*/
class ErUnknownTable : public DbEr{
public:
	ErUnknownTable(char *str = "Unknown table "){info = str;}
};

/**
* @class ErUnknownColumn
* @brief the unknown column exception
*/
class ErUnknownColumn : public DbEr{
public:
	ErUnknownColumn(char *str = "Unknown column "){info = str;}
};

/**
* @class ErTooLongIdent
* @brief the too long identifier name exception
*/
class ErTooLongIdent : public DbEr{
public:
	ErTooLongIdent(char *str = NULL){
		if(!str){
			char temp[10];
			str = new char(40);
			strcpy(str, "Indentifier name is too long, the max length is ");
			itoa(MaxIdentLen, temp, 10);
			strcat(str, temp);
			info = str;
		}
	}
};

/**
* @class ErDupColumn
* @brief the duplicate column name exception
*/
class ErDupColumn : public DbEr{
public:
	ErDupColumn(char *str = "Duplicate column name "){info = str;}
};

/**
* @class ErDupKey
* @brief the duplicate key name exception
*/
class ErDupKey : public DbEr{
public:
	ErDupKey(char *str = "Duplicate key name "){info = str;}
};

/**
* @class ErEmptyQuery
* @brief the empty query exception
*/
class ErEmptyQuery : public DbEr{
public:
	ErEmptyQuery(char *str = "Query was empty"){info = str;}
};

/**
* @class ErMultiPriKey
* @brief the multiple primary key exception
*/
class ErMultiPriKey : public DbEr{
public:
	ErMultiPriKey(char *str = "Multiple primary key defined"){info = str;}
};

/**
* @class ErTooManyKeys
* @brief the too many keys specified exception
*/
class ErTooManyKeys : public DbEr{
public:
	ErTooManyKeys(char *str = "Too many keys specified, only one key allowed"){info = str;}
};

/**
* @class ErKeyNotExist
* @brief the key not existing exception
*/
class ErKeyNotExist : public DbEr{
public:
	ErKeyNotExist(char *str = "Key column does not exist"){info = str;}
};

/**
* @class ErIndexNotExist
* @brief the index not existing exception
*/
class ErIndexNotExist : public DbEr{
public:
	ErIndexNotExist(char *str = "Index does not exist"){info = str;}
};

/**
* @class ErUnknownError
* @brief the unknown error exception
*/
class ErUnknownError : public DbEr{
public:
	ErUnknownError(char *str = "Unknown error"){info = str;}
};

/**
* @class ErLackColumn
* @brief the lacking columns in table exception
*/
class ErLackColumn : public DbEr{
public:
	ErLackColumn(char *str = "A table must have one column"){info = str;}
};

/**
* @class ErTooManyColumns
* @brief the too many columns exception
*/
class ErTooManyColumns : public DbEr{
public:
	ErTooManyColumns(char *str = "Too many columns"){info = str;}
};

/**
* @class ErSyntax
* @brief the syntax error exception
*/
class ErSyntax : public DbEr{
public:
	ErSyntax(char *str = "Syntax error"){info = str;}
};

/**
* @class ErLogIndexRead
* @brief the reading log index file exception
*/
class ErLogIndexRead : public DbEr{
public:
	ErLogIndexRead(char *str = "Reading log index file error"){info = str;}
};

/**
* @class ErSQLFile
* @brief the opening SQL file exception
*/
class ErSQLFile : public DbEr{
public:
	ErSQLFile(char *str = "Unable to open the SQL file"){info = str;}
};

/**
* @class ErQuit
* @brief the quit exception
*/
class ErQuit : public DbEr{
public:
	ErQuit(char *str = "Bye"){info = str;}
};

//int main(){
//	ercreatefile e;
//	exception("Can't create file")
//	e.what();
//	exception e;
//	cout << e.
//}

#endif // _miniSQL_H