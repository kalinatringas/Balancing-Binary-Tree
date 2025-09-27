#pragma once
#include <vector>
#include <iostream>
using namespace std;

class TreeNode{
    public:
    string ID; // userID
    string name; //user name
    TreeNode *left; 
    TreeNode *right;
    int height;    
    TreeNode(): ID(""), name(""), left(nullptr), right(nullptr){}
    TreeNode (string x, string y) : ID (x), name(y), left(nullptr), right(nullptr), height(1){}
   // TreeNode (string x, string y, TreeNode *left, TreeNode *right): ID(x), left(left), right(right) {}

};

class Tree{

    private: 
    TreeNode* root; //a pointer to the root!
    int height(TreeNode* node){
            return node? node->height: 0; // checks the node, what level is it at? 
        }

    void updateHeight( TreeNode * node){
        if (node) node->height = 1 + max(height(node->left), height(node->right)); //updates the nodes height based on its location
    }
    
    int balanceFactor(TreeNode * node){
        if (node == nullptr){
            return 0;
        }
        return height(node->left) - height(node->right);
    }
    TreeNode* rightRotate(TreeNode* y){
        TreeNode* x = y->left; //grab the node to the left of the input first
        TreeNode* T2 = x->right; // temporary hold
        x->right = y ; 
        y->left = T2; //TWO SWAPS TO ROTATE
        updateHeight(x); //update the height value, handy!
        updateHeight(y);
        return x;
    }

    TreeNode * leftRotate(TreeNode* x){
        TreeNode* y = x->right; //same logic as before, but flipped cause we are going left
        TreeNode* T2 = y->left;
        y->left = x;
        x->right = T2;
        updateHeight(x);
        updateHeight(y);
        return y;
    }

    TreeNode* balance(TreeNode *node){
        if (node == nullptr){return node;}
        
        updateHeight(node);
        int bf = balanceFactor(node); //helper function will tell us how much we have to balance by

        //First we do the L case, which means that the left size is heavy
        if (bf > 1 && balanceFactor(node->left)>=0){
                return rightRotate(node);
        }
        //this is the LR case, left heavy and then we do TWO rotations! to fix!
        if(bf > 1 && balanceFactor(node->left) < 0){ 
            node ->left = leftRotate(node);
            return rightRotate(node);
        }
        // RIGHT case! right side is heavy so we rotate left
        if (bf < -1 && balanceFactor(node->right)>= 0){
            return leftRotate(node);
        }
        // finally the RL case!
        if( bf < -1 && balanceFactor(node->right) < 0){
            node->right = rightRotate(node);
            return leftRotate(node); // i always find it so interest how you end going the opposite of the side you are heavy on. a way to remember
        }
        return node;
    }

    TreeNode* insert(TreeNode* node, string id, string Name){
        if (node == nullptr){
            TreeNode* newNode = new TreeNode; 
            newNode->height = 1;
            newNode->ID = id;
            newNode->name = Name; 
            newNode->left = nullptr;
            newNode->right = nullptr;
            cout << "successful" <<endl;
            return newNode;

        }
        if (id < node ->ID) { //if root ID is greater, move to the left
            node -> left = insert(node->left, id, Name);
        }
        else if (id > node->ID){   
            node -> right = insert(node->right, id,Name);
        }   
        else{
            cout << "unsuccessful"<< endl;
            return node;
        }
        updateHeight(node);
        balance(node);
        return node;
    }

    TreeNode* remove(TreeNode* node, string id){
        if (node == nullptr){
            return nullptr;
        }
        if (id < node ->ID) { //if node ID is greater, move to the left
            node -> left = remove(node->left, id);
        }
        else if (id > node->ID){
            node -> right = remove(node->right, id);
        }
        return node;
    }

    TreeNode* searchID(TreeNode* node, const string& target) {
        if (node == nullptr || node->ID == target) {
            return node; // base case
        }
        if (node->ID > target) {
            return searchID(node->left, target);
        }
        else if (node->ID < target) {
            return searchID(node->right, target);
        } else {
            cout << "Error" << endl;
            return node;
        }
    }

    void searchName (TreeNode* node, const string& target, vector<string>& ids){
        if (node == nullptr){
            return;
        }
        // we do a pre order traveral of the entire tree
        if (node->name == target){
            ids.push_back(node->ID);
        }
        searchName(node->left, target,ids);
        searchName(node->right, target,ids);
    }

    void inorder(TreeNode* node, vector<string>& result){
        // LRN
        if (!node){return;}
        inorder(node->left, result);
        result.push_back(node->name);
        inorder(node->right, result);
        cout << "successful" << endl;

    }

    void preorder(TreeNode* node, vector<string>& result){
        //NLR
        if(!node){return;}
        result.push_back(node->name);
        preorder(node->left, result);
        preorder (node->right, result);
    }
    
    void postorder(TreeNode* node, vector<string>& result){
        //LRN
        if (!node){return;}
        postorder(node->left, result);
        postorder(node-> right, result);
        result.push_back(node->name);
    }
    void findNthInOrder(TreeNode* node, int& n, string& foundID){
        if (node == nullptr || foundID.empty()){
            return;
        }
        findNthInOrder(node->left, n, foundID);
        if (foundID.empty()) {
            if (n == 0) {
                foundID = node->ID;
            }
            n--;
        }
        findNthInOrder(node->right, n, foundID);

    }

    public:
    
    Tree(): root(nullptr){}

    ~Tree(){
        string idTo_remove;
        while(root!= nullptr){
            idTo_remove = root->ID;
            remove(idTo_remove);
        }
    }

    void insert(string id, string name){
        root = insert(root, id, name);
        cout << "successful" << endl;
    }

    void remove(string id) {
        root = remove(root, id);
        cout << "successful" << endl;
    }

    // this pubic methond searches for id
    
    

    void printinorder(){
        vector<string> result;
        inorder(root, result);
        for (int i = 0; i < result.size(); i++){
            cout << result[i]<< ", " ;
        }
        cout << endl;
        
    }
    void printpreorder(){
        vector<string> result;
        preorder(root, result);
        for (int i = 0; i < result.size(); i++){
            cout << result[i]<< ', ';
        }
        cout << endl;
    }
    void printLevelCount(){}
    void clear(){}

    string search(string target, string type){
        if (type == "name"){

        } else if (type == "ID"){
            root = searchID(root, target);
        }
        return "yes";
    }
    
    
};  