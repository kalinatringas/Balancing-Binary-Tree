//#include <catch2/catch_test_macros.hpp>
//#include <catch/catch_amalgamated.hpp>
#include "catch/catch_amalgamated.hpp"
#include <iostream>
#include <string>
#include <vector>
// Kalina Tringas 93304875

// uncomment and replace the following with your own headers
#include "../src/Tree.h"
#include "../src/ProcessCommand.h"

using namespace std;

// the syntax for defining a test is below. It is important for the name to be unique, but you can group multiple tests with [tags]. A test can have [multiple][tags] using that syntax.
TEST_CASE("Invalid Commands", "[commands]"){
	Tree tree;
	REQUIRE_FALSE(processCommand(tree, "insert"));// icomplete insert
	REQUIRE_FALSE(processCommand(tree, "delete")); // not a thing
	REQUIRE_FALSE(processCommand(tree, "insert A11y")); // incomplete
	REQUIRE_FALSE(processCommand(tree,"remove")); // missing arguments
	REQUIRE_FALSE(processCommand(tree, "foobar")); // NOT AN acutal thang
	 
}

TEST_CASE("Insertions", "[insert]"){
	// you can also use "sections" to share setup code between tests, for example:
	Tree tree; 
	tree.insert("10000002", "TOP");
	tree.insert("10000001", "LEFT");
	tree.insert("10000003", "RIGHT");
	REQUIRE(tree.root->ID == "10000002");

	tree.clear(); // reset the tree 

	// LL
	tree.insert("10000003", "RIGHT");
	tree.insert("10000002", "TOP");
	tree.insert("10000001", "LEFT");
	REQUIRE(tree.root->ID == "10000002");
	
	// RR ROTATION
	tree.insert("10000001", "LEFT");
	tree.insert("10000002", "TOP");
	tree.insert("10000003", "RIGHT");
	REQUIRE(tree.root->ID == "10000002");

	tree.clear();
	//LR ROTATION
	tree.insert("10000003", "RIGHT");
	tree.insert("10000001", "LEFT");
	tree.insert("10000002", "TOP");
	REQUIRE(tree.root->ID == "10000002");

	// RL ROTATION
	tree.clear();
	tree.insert("10000001", "LEFT");
	tree.insert("10000003", "RIGHT");
	tree.insert("10000002", "TOP");
	
	REQUIRE(tree.root->ID == "10000002");


	// each section runs the setup code independently to ensure that they don't affect each other
}

// you must write 5 unique, meaningful tests for credit on the testing portion of this project!

// the provided test from the template is below.

// TEST_CASE("Insert and delete bulk", "[bulk]"){
// 	Tree tree; // tree object hellO!
// 	for (int i = 1 ; i <= 100; i++){
// 		tree.insert(to_string(20000000-i), "Name" + to_string(i));
// 	}
// 	REQUIRE(tree.size() == 100);

// 	vector<string> removed = {"5","10","15","20","25","30","35","40","45","50"};
// 	for (string id : removed){
// 		tree.remove(id);
// 	}
// 	REQUIRE(tree.size() == 90);

// 	auto inorder = tree.printinorder();
// 	REQUIRE(inorder.size() == 90);
// 	for (int i =1 ; i <= 100; i++){
// 		if (find(removed.begin(), removed.end(), i) == removed.end()){
// 			REQUIRE(find(inorder.begin(), inorder.end(), i) != inorder.end());
// 		}
// 	} //should be sorted, do not contain removed elements


// }
