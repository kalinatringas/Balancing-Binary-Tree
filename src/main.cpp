#include <iostream>
#include <sstream>
#include "Tree.h"
#include "ProcessCommand.h"
//#include "ProcessCommand.cpp" //comment out for gradescope
using namespace std;

int main(){
	//cout << "How many commands will you be inputting? :" ;
	int cmdNum;
	cin >> cmdNum;
	cin.ignore();
	Tree tree;
//	TreeNode* root = nullptr;
	string line;
	// getline(cin, line);  //rest of the lline
	
	for (int i = 0; i < cmdNum ; i++){
		getline(cin, line);
		stringstream ss(line);
		string command;
		ss >> command; 
		processCommand(tree,line);
		// if(!processCommand(tree, line))	{
		// 	cout<< "unsuccessful" << endl;
		// }
	}	
	return 0;
}
