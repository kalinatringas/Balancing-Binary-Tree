#include <iostream>
#include <sstream>
#include "Tree.h"

using namespace std;


TreeNode* insert(TreeNode* root, int key){
	if (root == nullptr){
		return new TreeNode(key);
	}
	if (key < root ->val) { //if root val is greater, move to the left
		root -> left = insert(root->left, key);
	}
	else{
		root -> right = insert(root->right, key);

	}
	return root;
}


int main(){
	cout << "Hello AVL!\n";
	cout << "How many commands will you be inputting? :" ;

	string cmd; 

	int cmdNum;
	for (int i = 0; i < cmdNum ; i++){
		cin >> cmd; 
		if (cmd == "insert"){
			string name;
			long long ID; 
			cin >> ws;
			getline(cin, name, '"');
			getline(cin, name, '"');
			cin >> ID; 
			//add to insert function 

		} else if (cmd == "remove"){
			//call remove function
		} else if (cmd == "printInorder"){
			//call printInorder function

		} else if (cmd == "removeInorder"){
			//call remove inorderfunction
		} else{
			cout<< "Invalid Input"<< endl; 
		}
		
		
	}


	return 0;
}
