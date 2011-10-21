/**
* @file
* @brief the test file of Interpreter
* @author elf@ZJU
* @version 1.0
*
* run the Interpreter and output the result to the screen
*/

#include "miniSQL.h"
#include "Interpreter.h"

/**
* @brief the main function
* @param none
* @exception ErCreateFile
* @return an integer
*/
int main(){
	cout << "Welcome to the miniSQL. Commands end with ;." << endl;
	cout << "Version 1.0. Copyright elf@ZJU. All rights reserved." << endl;
	cout << "\nType 'help;' or '\h' for help. Type '\c' to clear the current input statement." << endl;
	while(1){
		try{
			//throw ErCreateFile();
			//throw ErTooLongIdent();
			HandleOneSQL(cin);
		}
		catch(ErQuit &e){
			cout << e.what() << endl;
			break;
		}
		catch(DbEr &e){
			cout << e.what() << endl;
		}
	}

	system("pause"); 
}