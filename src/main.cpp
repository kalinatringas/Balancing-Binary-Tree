#include <iostream>
#include <sstream>
#include "Tree.h"
#include "ProcessCommand.h"

using namespace std;




int main(){
	cout << "Hello AVL!\n";
	cout << "How many commands will you be inputting? :" ;
	int cmdNum;
	cin >> cmdNum;
	cin.ignore();
	Tree tree;
//	TreeNode* root = nullptr;
	string line;
	
	for (int i = 0; i < cmdNum ; i++){
		getline(cin, line);
		if(!processCommand(tree, line))	{
			cout<< "unsuccessful" << endl;
		}
	}	
	return 0;
}
