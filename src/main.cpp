#include <iostream>
#include <sstream>
#include "Tree.h"

using namespace std;

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
			if (id.empty()) return false;
			tree.remove(id);
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


int main(){
	cout << "Hello AVL!\n";
	cout << "How many commands will you be inputting? :" ;
	int cmdNum;
	cin >> cmdNum;
	cin.ignore();
	Tree tree;
	TreeNode* root = nullptr;
	string line;
	
	for (int i = 0; i < cmdNum ; i++){
		getline(cin, line);
		if(!processCommand(tree, line))	{
			cout<< "invalidinnput" << endl;
		}	
	}	
	return 0;
}
