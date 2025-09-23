using namespace std;
#include "ProcessCommand.h"
#include <sstream>
#include <iostream>

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
		} else if (cmd == "printInorder"){
			//call printInorder function
			tree.printinorder();
			return true;

		} else if (cmd == "removeInorder"){
			//call remove inorderfunction
			tree.removeinorder();
			return false;
		}

}