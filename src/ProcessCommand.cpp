using namespace std;
#include "ProcessCommand.h"
#include <sstream>
#include <iostream>
#include <cctype>
#include <regex>


bool isValidGatorID(string& id){
	regex idRegex("^[0-9]{8}$"); // shoudl be only looking at digits between 0 adn 9 and 8 chars long
	return regex_match(id, idRegex);
}

bool isValidName(string & name){
	regex nameRegex("^[a-zA-Z\\s]+$"); // also only looks at abc characters
	return regex_match(name, nameRegex); 
}

string parsedQuote ( istream &is){
	string token;
	if (is.peek() == '"'){
		is.get(); 
		getline(is, token, '"');
	}
	return token;
}

bool processCommand(Tree& tree, const string& line){	
	stringstream ss(line);
	string cmd;
	ss >> cmd;
	if (cmd == "insert"){
			string name, id;
			char quote;
			ss >> quote; // reads the opening quote "
			getline(ss, name, '"'); // reads until closing quote
			ss >> ws >> id; // reads ID with whitespace skip
        
			// recoding it here just in case, help. 
			regex nameRegex("^[a-zA-Z\\s]+$");
			regex idRegex("^[0-9]{8}$");
        
			if (regex_match(name, nameRegex) && regex_match(id, idRegex)) {
				tree.insert(id, name);
			} else {
				cout << "unsuccessful" << endl;
			}
	
		} else if (cmd == "remove"){
			//call remove function
			string ID;
			ss>> ID;

			if(isValidGatorID(ID)){
				tree.remove(ID);
			} else{
				return false;
			}
			
			return true;
		} else if (cmd == "search"){
			string token;
			ss >> token;
			
			if (token.front() == '"') {
       
				stringstream tempSS(token);
				string name = parsedQuote(tempSS);
				
				//cout << "DEBUG: Parsed name: '" << name << "'" << endl;
				
				if (isValidName(name)) {
					tree.searchName(name);
				} else {
					cout << "unsuccessful" << endl;
				}
			} else {
				// ID search
				if (isValidGatorID(token)) {
					tree.searchID(token);
				} else {
					cout << "unsuccessful" << endl;
				}
			}
			return true; // Return true at the end
		} else if (cmd == "printInorder"){		
			//call printInorder function
			tree.printInorder();
			return true;

		} else if (cmd == "printPreorder"){
			tree.printpreorder();
			return true;
		} else if(cmd == "printPostorder") {
			tree.printpostorder();
			return true;
		}
		else if (cmd == "printLevelCount"){
			tree.printLevelCount();
			return true;
		}
		 else if (cmd == "removeInorder"){
			//call remove inorderfunction
			int n;
            ss >> n;
			tree.removeInorder(n);
		
			return true;
		} else{
			cout << "unsuccessful" << endl;
			return false;
		}
		return false;
	}

	/*
	Graveyard

		old search logic
		// string ID; 
			// ss>> ID;
			// string type;
			// if (ID.size() == 8 && isdigit(ID[0])){
			// 	type = "ID";
			// } else{
			// 	type = "name";
			// }

			// tree.search(ID, type);// have to make one for names too
			// return true; 	
	*/