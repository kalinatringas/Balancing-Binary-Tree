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
        cout << "successful" << endl;
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
        cout << "successful" << endl;
    }

    void inorder(TreeNode* root, vector<string>& result){
        // LRN
        if (!root){return;}
        inorder(root->left, result);
        result.push_back(root->name);
        inorder(root->right, result);
        cout << "successful" << endl;

    }

    void preorder(TreeNode* root, vector<string>& result){
        //NLR
        if(!root){return;}
        result.push_back(root->name);
        preorder(root->left, result);
        preorder (root->right, result);
    }
    
    void postorder(TreeNode* root, vector<string>& result){
        //LRN
        if (!root){return;}
        postorder(root->left, result);
        postorder(root-> right, result);
        result.push_back(root->name);
    }

    vector<string> printinorder(){
        vector<string> result;
        inorder(root, result);
        for (int i = 0; i < result.size(); i++){
            cout << result[i]<< ", " ;
        }
        cout << endl;
    }
    vector<string> printpreorder(){
        vector<string> result;
        preorder(root, result);
        for (int i = 0; i < result.size(); i++){
            cout << result[i]<< ', ';
        }
        cout << endl;
    }
    int printLevelCount(){}
    void clear(){}

    TreeNode* searchID(TreeNode* node, string target){
        if ( node->ID > target){
            // GO LEFT
            node->left = searchID(root, target);
        }
        else if (node ->ID < target){
            node->right = searchID(root, target);
        } else if (node -> ID == target){
            return node;
        } else{
            cout << "Error searching IDs" << endl;
        }
    }

    string search(string target, string type){
        if (type == "name"){

        } else if (type == "ID"){
            root = searchID(root, target);
        }
        
    }
    void removeinorder(){

    }
    
};  