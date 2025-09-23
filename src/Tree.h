#pragma once
#include <vector>

using namespace std;

class TreeNode{
    public:
    string ID; // userID
    string name; //user name
    TreeNode *left; 
    TreeNode *right;    
    TreeNode(): ID(""), name(""), left(nullptr), right(nullptr){}
    TreeNode (string x, string y) : ID (x), name(y), left(nullptr), right(nullptr){}
    TreeNode (string x, string y, TreeNode *left, TreeNode *right): ID(x), left(left), right(right) {}

};

class Tree{
   public:
    TreeNode* root; //a pointer to the root!

    Tree(): root(nullptr){}

    TreeNode* insert(TreeNode* root, string id, string name){
        if (root == nullptr){
            return new TreeNode(id, name);
        }
        if (id < root ->ID) { //if root ID is greater, move to the left
            root -> left = insert(root->left, id, name);
        }
        else{
            root -> right = insert(root->right, id,name);

        }   
        return root;
    }

    void insert(string id, string name){
        root = insert(root, id, name);
    }

    TreeNode* remove(TreeNode* root, string id){
        if (root == nullptr){
            return nullptr;
        }
        if (id < root ->ID) { //if root ID is greater, move to the left
            root -> left = remove(root->left, id);
        }
        else if (id > root->ID){
            root -> right = remove(root->right, id);
        }//need to add the actual removal stuff
        return root;
    }

    void remove(string id) {
        root = remove(root, id);
    }

    void inorder(TreeNode* root, vector<string>& result){
        if (!root){return;}
        inorder(root->left, result);
        result.push_back(root->ID);
        inorder(root->right, result);

    }

    vector<string> printinorder(){}
    // ADD REMOVE CLEAR AND SIZE AND PRINT IN ORDER

    void clear(){}
    int size(){ return 0;}

    //i would like to put the insert, delete fun
    // ctions in here? 
    void removeinorder(){}
    
};  