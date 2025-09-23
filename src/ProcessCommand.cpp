using namespace std;
#include "ProcessCommand.h"
#include <sstream>
#include <iostream>
#include <cctype>

bool processCommand(Tree& tree, const string& line){	
	stringstream ss(line);
	string cmd;
	ss >> cmd;
	if (cmd == "insert"){
			string name;
			string ID; 
			ss >> ws;
			getline(cin, name, '"');
			getline(cin, name, '"');
			cin >> ID; 
			//add to insert function 
			tree.insert(ID, name);
			return true;
		

		} else if (cmd == "remove"){
			//call remove function
			string ID;
			ss>> ID;
		
			tree.remove(ID);
			return true;
		} else if (cmd == "search"){
			string ID; 
			ss>> ID;
			string type;
			if (ID.size() == 8 && isdigit(ID[0])){
				type = "ID";
			} else{
				type = "name";
			}

			tree.search(ID, type);// have to make one for names too
			return true; 
		}
		else if (cmd == "printInorder"){
			//call printInorder function
			tree.printinorder();
			return true;

		} else if (cmd == "printPreorder"){
			tree.printpreorder();
			return true;
		} else if (cmd == "printLevelCount"){
			tree.printLevelCount();
			return true;
		}
		 else if (cmd == "removeInorder"){
			//call remove inorderfunction
			tree.removeinorder();
			return false;
		}

}