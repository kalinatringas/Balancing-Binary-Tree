// //#include <catch2/catch_test_macros.hpp>
// //#include <catch/catch_amalgamated.hpp>
// #define CATCH_CONFIG_MAIN
// #include "catch/catch_amalgamated.hpp"
// #include <iostream>
// #include <string>
// #include <vector>
// // Kalina Tringas 93304875
// #include "../src/Tree.cpp"
// #include "../src/ProcessCommand.h"

// using namespace std;

// TEST_CASE("Invalid Commands", "[commands]"){ // at least five incorrect commands
// 	Tree tree;
// 	REQUIRE_FALSE(processCommand(tree, "insert"));// incomplete insert
// 	REQUIRE_FALSE(processCommand(tree, "delete")); // not a thing
// 	REQUIRE_FALSE(processCommand(tree, "insert A11y")); // incomplete
// 	REQUIRE_FALSE(processCommand(tree,"remove")); // missing arguments
// 	REQUIRE_FALSE(processCommand(tree, "foobar")); // NOT AN acutal thang
	 
// }

// TEST_CASE("Insertions and Rotations", "[insert]"){ //rotations
// 	SECTION("FIRST CHECK"){
// 		Tree tree; 
// 		tree.insert("10000002", "TOP");
// 		tree.insert("10000001", "LEFT");
// 		tree.insert("10000003", "RIGHT");
// 		REQUIRE(tree.getRootID() == "10000002");
// 	}
// 	// LL
// 	SECTION("LL Rotation"){
// 		Tree tree;
// 		tree.insert("10000003", "RIGHT");
// 		tree.insert("10000002", "TOP");
// 		tree.insert("10000001", "LEFT");
// 		REQUIRE(tree.getRootID() == "10000002"); 
// 	}
	
// 	// RR ROTATION
// 	SECTION("RR ROTATION"){
// 		Tree tree;
// 		tree.insert("10000001", "LEFT");
// 		tree.insert("10000002", "TOP");
// 		tree.insert("10000003", "RIGHT");
// 		REQUIRE(tree.getRootID() == "10000002");
// 	} // i wish i could add little diagrams in my code T_T

// 	//LR ROTATION
// 	SECTION("LR ROTATION"){
// 		Tree tree;
// 		tree.insert("10000003", "RIGHT");
// 		tree.insert("10000001", "LEFT");
// 		tree.insert("10000002", "TOP");
// 		REQUIRE(tree.getRootID() == "10000002");
// 	}


// 	// RL ROTATION
// 	SECTION("RL ROTATION"){
// 		Tree tree;
// 		tree.insert("10000001", "LEFT");
// 		tree.insert("10000003", "RIGHT");
// 		tree.insert("10000002", "TOP");	
// 		REQUIRE(tree.getRootID()== "10000002");
// 	}

// 	// each section runs the setup code independently to ensure that they don't affect each other!! 
// }


// TEST_CASE("Edge cases, removing non-existent node", "[edge]") {
//     Tree tree;
//     tree.insert("10000002", "B");
//     tree.insert("10000001", "A");
//     tree.insert("10000003", "C");

//     REQUIRE_FALSE(tree.remove("Q"));// can only remove by ID
// 	REQUIRE_FALSE(tree.remove("10000007")); // non existant 
   
// }

// TEST_CASE("Deletion Cases", "[delete]"){ /// segmentation errors {RESOLVED! YAY}
// 	SECTION("one child"){
// 		Tree tree;
// 		tree.insert("10000002", "Two");
// 		tree.insert("10000003", "Three");
// 		tree.insert("10000004", "Four");
// 		tree.insert("10000005", "Five"); //root node
// 		tree.insert("10000007", "Seven");
// 		//tree.insert("10000008", "Eight");
// 		tree.insert("10000006", "Six"); 
// 		REQUIRE(tree.remove("10000007"));
// 		REQUIRE_FALSE(tree.searchID("10000007"));

// 	}
// 	SECTION("two children"){
// 		Tree tree;
// 		tree.insert("10000002", "Two");
// 		tree.insert("10000003", "Three");
// 		tree.insert("10000004", "Four");
// 		tree.insert("10000005", "Five"); //root node
// 		tree.insert("10000007", "Seven");
// 		tree.insert("10000008", "Eight");
// 		tree.insert("10000006", "Six"); 
// 		REQUIRE(tree.remove("10000003"));
// 		REQUIRE_FALSE(tree.searchID("10000003"));

// 	}
// 	SECTION("no children"){
// 		Tree tree;
// 		tree.insert("10000002", "Two");
// 		tree.insert("10000003", "Three");
// 		tree.insert("10000004", "Four");
// 		tree.insert("10000005", "Five"); //root node
// 		tree.insert("10000007", "Seven");
// 		tree.insert("10000008", "Eight");
// 		tree.insert("10000006", "Six"); 
// 		REQUIRE(tree.remove("10000002"));
// 		REQUIRE_FALSE(tree.searchID("10000002"));
// 	}
// }

// TEST_CASE("Stress Test Case", "[stress]"){
//     Tree inputTree;
//     vector<string> names;
//     set<string> uniqueIDs; // to avoid duplicates #livelaughlovesets 
    
//     srand(12345); //using a seed so its not totally random haha
//     for(int i = 0; i < 1000; i++) {
//         string id;
//         while (uniqueIDs.count(id) > 0){
// 			int randomNum = 10000000 + (rand() % 90000000); // making sure that it is 8 digits long, thank you modulus 
//             id = to_string(randomNum);
// 		}
        
//         uniqueIDs.insert(id);
//         string name = "User" + to_string(i);
//         names.push_back(name);
//         inputTree.insert(id, name);
//     }
    
//     vector<string> actualOutput = inputTree.printinorder();
//     REQUIRE(actualOutput.size() == 1000);
    
//     // make sure that the tree height is as expected (should be O(log n), cause like that the whole point)
//     int height = inputTree.printLevelCount();
//     REQUIRE(height <= 15); // i'm using 15 should be safe upper bound bc log2(1000) = 10 (ish)
    
//     // make sure inorder traversal gives sorted names by ID
//     vector<string> sortedNames = names;
//     vector<string> sortedIDs(uniqueIDs.begin(), uniqueIDs.end()); 
    
//     // inorder traversal should be same as the sorted ID order
//     REQUIRE(actualOutput.size() == sortedNames.size());
// }

// TEST_CASE("Traversal Orders", "[flag]"){
//     Tree inputTree;
//     inputTree.insert("10000005", "Root");    // my root
//     inputTree.insert("10000003", "Left");    // l child (not a w baby)
//     inputTree.insert("10000007", "Right");   // r child
//     inputTree.insert("10000002", "LeftLeft"); // left-left
//     inputTree.insert("10000004", "LeftRight"); // left-right
    
//     // store all traversals make sure code doesn't explode
//     vector<string> inorderResult = inputTree.printinorder();
//     vector<string> preorderResult = inputTree.printpreorder();
//     vector<string> postorderResult = inputTree.printpostorder();
    
//     // inorder should be sorted by ID
//     vector<string> expectedInorder = {"LeftLeft", "Left", "LeftRight", "Root", "Right"};
//     REQUIRE(inorderResult == expectedInorder);
    
//     // ALL should have same size!
//     REQUIRE(inorderResult.size() == preorderResult.size());
//     REQUIRE(inorderResult.size() == postorderResult.size());
//     REQUIRE(preorderResult.size() == 5);
//     REQUIRE(postorderResult.size() == 5);
// }