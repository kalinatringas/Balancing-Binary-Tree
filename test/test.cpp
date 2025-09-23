#include <iostream>
#define CATCH_CONFIG_MAIN  
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include "../src/Tree.h"

// uncomment and replace the following with your own headers
// #include "AVL.h"

using namespace std;

// the syntax for defining a test is below. It is important for the name to be unique, but you can group multiple tests with [tags]. A test can have [multiple][tags] using that syntax.
TEST_CASE("Invalid Commands", "[flag]"){
	 
}

TEST_CASE("Insertions", "[flag]"){
	// you can also use "sections" to share setup code between tests, for example:
	Tree tree; 
	tree.insert(10);
	tree.insert(5);
	tree.insert(15);
	REQUIRE(tree.root->ID == 10);

	tree.clear(); // reset the tree 

	// LL
	tree.insert(30);
	tree.insert(20);
	tree.insert(10);
	REQUIRE(tree.root->ID == 20);
	
	// RR ROTATION
	tree.insert(10);
	tree.insert(20);
	tree.insert(30);
	REQUIRE(tree.root->ID == 20);

	tree.clear();
	//LR ROTATION
	tree.insert(30);
	tree.insert(10);
	tree.insert(20);
	REQUIRE(tree.root->ID == 20);

	// RL ROTATION
	tree.clear();
	tree.insert(10);
	tree.insert(30);
	tree.insert(20);
	REQUIRE(tree.root->ID == 20);


	// each section runs the setup code independently to ensure that they don't affect each other
}

// you must write 5 unique, meaningful tests for credit on the testing portion of this project!

// the provided test from the template is below.

TEST_CASE("Insert and delete bulk", "[flag]"){
	/*
		MyAVLTree tree;   // Create a Tree object
		tree.insert(3);
		tree.insert(2);
		tree.insert(1);
		std::vector<int> actualOutput = tree.inorder();
		std::vector<int> expectedOutput = {1, 2, 3};
		REQUIRE(expectedOutput.size() == actualOutput.size());
		REQUIRE(actualOutput == expectedOutput);
	*/
	Tree tree; // tree object hellO!
	for (int i = 1 ; i <= 100; i++){
		tree.insert(i);
	}
	REQUIRE(tree.size() == 100);

	vector<int> removed = {5,10,15,20,25,30,35,40,45,50};
	for (int id : removed){
		tree.remove(id);
	}
	REQUIRE(tree.size() == 90);


}
