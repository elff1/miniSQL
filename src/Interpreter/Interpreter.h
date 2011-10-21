/**
* @file
* @brief the header file of Interpreter
* @author elf@ZJU
* @version 1.0
*
* contains a test class
*/

#ifndef _Interpreter_H
#define _Interpreter_H

#include "miniSQL.h"

/**
* @class MyClass
* @brief a test class
*/
class MyClass {
	public:
		int k;	///< first public member
		/** @brief a test function */
		int fun();
	private:
		int j;	///< first private member
};

/**
* the command type enum
*/
enum CmdType{
	CreateTableType,
	CreateIndexType,
	ExecFileType,
	QuitType
};

/** @brief get a SQL from in and handle it */
void HandleOneSQL(istream &in);

/** @brief check the left quotation mark */
bool CheckLeftQuote(string &str);

/** @brief get the command type */
CmdType GetCmdType(string &sql);

/** @brief execute SQLs from a file */
void ExecFile(string &fileName);

#endif // _Interpreter_H
