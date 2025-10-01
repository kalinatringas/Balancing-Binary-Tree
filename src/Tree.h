#pragma once
#include <vector>
#include <string>
using namespace std;
#include <iostream>
#include <regex>

class TreeNode{
    public:
    string ID; // userID
    string name; //user name
    TreeNode *left; 
    TreeNode *right;
    int height;

    TreeNode() : ID(""), name(""), left(nullptr), right(nullptr), height(1) {}
    TreeNode(const string& x, const string& y) : ID(x), name(y), left(nullptr), right(nullptr), height(1) {}// TreeNode (string x, string y, TreeNode *left, TreeNode *right): ID(x), left(left), right(right) {}

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
        if (!y || !y->left) return y;
        TreeNode* x = y->left; //grab the node to the left of the input first
        TreeNode* T2 = x->right; // temporary hold
        x->right = y ; 
        y->left = T2; //TWO SWAPS TO ROTATE 
        updateHeight(y); 
        updateHeight(x); //update the height value, handy!
        return x;
    }

    TreeNode * leftRotate(TreeNode* x){
        if (!x || !x->right) return x;
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

        //First we do the LL case, which means that the left size is heavy
        if (bf > 1 && balanceFactor(node->left)>=0){
                return rightRotate(node);
        }
        //this is the LR case, left heavy and then we do TWO rotations! to fix!
        if(bf > 1 && balanceFactor(node->left) < 0){ 
            node -> left = leftRotate(node->left);
            return rightRotate(node);
        }
        // RIGHT case! right side is heavy so we rotate left
        if (bf < -1 && balanceFactor(node->right)<= 0){
            return leftRotate(node);
        }
        // finally the RL case!
        if( bf < -1 && balanceFactor(node->right) > 0){
            node->right = rightRotate(node->right);
            return leftRotate(node); // i always find it so interest how you end going the opposite of the side you are heavy on. a way to remember
        }
        return node;
    }

    TreeNode* insert(TreeNode* node, const string& id, const string& Name, bool& success){
        if (node == nullptr){
            success = true;
            TreeNode* newNode = new TreeNode(id, Name); 
            return newNode;

        }
        if (id < node ->ID) { //if root ID is greater, move to the left
            node -> left = insert(node->left, id, Name, success);
        }
        else if (id > node->ID){   
            node -> right = insert(node->right, id,Name, success);
        }   
        else{
            //cout << "unsuccessful"<< endl;
            success = false;
            return node;
        }
        updateHeight(node);
        //node = balance(node);
        return balance(node);
    }
    // helper function for the remove function down there
    TreeNode* findMin(TreeNode* node) {
        if (node == nullptr){return nullptr;}
        TreeNode* curr = node;// curr for current
        while (curr->left != nullptr) {
            curr = curr->left;
        }
        return curr;
    }

    TreeNode* remove(TreeNode* node, string id){
        if (node == nullptr){return nullptr;}

        if (id < node ->ID) { //if node ID is greater, move to the left         
            node -> left = remove(node->left, id);
        }
        else if (id > node->ID){
            node -> right = remove(node->right, id);
        } else{
            //the node that needs to be deleted is found
            // check to see if no children
            if (node -> left == nullptr && node -> right == nullptr){ // this is looking at one child 
               // NO CHILDREN
               delete node;
               return nullptr;
            } else if (node->left == nullptr){ // both children are here
                // Case 2 right (1 child)
                TreeNode* temp = node->right;
                delete node;
                return temp; 
            } else if (node->right == nullptr){
                // left case
                TreeNode* temp = node->left;
                delete node;
                return temp;
            } else{
                // two children
                TreeNode* temp = findMin(node->right);
                node->ID = temp->ID;
                node->name = temp->name; // copy over
                node->right = remove(node->right, temp->ID);
            }
        }
        // tree is only root
        //if (node == nullptr){return nullptr;}

        updateHeight(node);
       
        return balance(node);
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
         //   cout << "unsuccessful" << endl;
            return node;
        }
    }

    void searchName (TreeNode* node, const string& target, vector<string>& ids){
        if (node == nullptr){
            return; 
        }
        // we do a pre order traveral of the entire tree
        if (node->name == target){
            ids.push_back(node->ID); //add to the vector 
        }
        searchName(node->left, target,ids); // recurisivly search
        searchName(node->right, target,ids); // i dislike this, but its all i can do. i can't find it without searching entire tree yknow
    }

    void inorder(TreeNode* node, vector<string>& result){
        // LRN. left right node
        if (!node){return;}
        inorder(node->left, result);
        result.push_back(node->name);
        inorder(node->right, result);
       // cout << "successful" << endl;
       // return result;

    }

    void preorder(TreeNode* node, vector<string>& result){
        //NLR, 
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
        if (node == nullptr || !foundID.empty()){
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

    void destroy(TreeNode* node) {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
// PUBLIC STUFF STARTS HERE !!!! :p 
public:
    string getRootID() const {
        if (!root) return "";
        return root->ID; // if Node has a getter
    }
    
    Tree(): root(nullptr){}
    
    ~Tree() {
        destroy(root);
    }



    void insert(const string & id, const string & name){
        bool success = false;
        root = insert(root, id, name, success);
        
       // cout << "After inserting " << name << ":" << endl;
       
        // TreeNode* oldRoot = root;
        // cout << "Height: " << height(root) << endl << endl;
        // cout << "DEBUG: Insert " << name << " - Root changed from " 
        //  << (oldRoot ? oldRoot->name : "null") << " to " 
        //  << (root ? root->name : "null") << endl;

        if (success){
            cout << "successful" << endl;
        } else {
            cout << "unsuccessful" << endl;
        }
        //root = insert(root, id, name);
        //cout << "successful" << endl; should already be printing
    }


    bool remove(string id) {
        //check to see if ID
        // to remove leading/trailing whitespace
        id.erase(0, id.find_first_not_of(" \t\n\r\f\v"));
        id.erase(id.find_last_not_of(" \t\n\r\f\v") + 1);
        regex idRegex("^[0-9]{8}$"); // shoudl be only looking at digits between 0 adn 9 and 8 chars long
       
       
         if(!regex_match(id, idRegex)){
            cout<< "unsuccessful" << endl;
            return false;
        }
        TreeNode* found = searchID(root,id);
        if (found== nullptr){
            cout<< "unsuccessful" << endl;
            return false;
        }
        
        root = remove(root, id);
        cout << "successful" << endl;
        return true;
    }

    // this pubic methond searches for id
    
    

    vector<string> printInorder(){
        vector<string> result;
        inorder(root, result);
       // debugNodeContents();
        for (int i = 0; i < result.size(); i++){
            cout << result[i];
            if (i < result.size() - 1) {
                cout << ", ";
        }
        }
        cout << endl;
        return result;
    }
    // copy same logic to pre and post
    vector<string> printpreorder(){
        vector<string> result;
        preorder(root, result);
        for (int i = 0; i < result.size(); i++){
           cout << result[i];
            if (i < result.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
        return result;
    }

    vector<string> printpostorder(){
        vector<string>result;
        postorder(root,result);
        for (int i = 0; i < result.size(); i++){
           cout << result[i];
            if (i < result.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
        return result;
    }

    bool removeInorder(int n){
        if (n < 1){
            cout<< "unsuccessful" << endl;
            return false;
        }

        string idToRemove = ""; 
        int nCopy = n;
        findNthInOrder(root, nCopy, idToRemove);
        // cout << "DEBUG: Looking for " << n << "th node in inorder traversal" << endl;
        
        // cout << "DEBUG: Found ID to remove: '" << idToRemove << "'" << endl;


        if(!idToRemove.empty()){
            root = remove(root, idToRemove); // make sure it updates
            cout << "successful" << endl;
            return true;
        } else{
            cout << "unsuccessful" << endl; //failure due to empty string
            return false; 
        }
    }

    int printLevelCount(){
        cout << height(root)<< endl;
        return height(root);
    }

    vector<string> searchName(const string& name){
        vector<string> ids;//cause there might be multiple
        searchName(root,name,ids); //this should call the priviate guy
        if (ids.empty()){
            cout << "unsuccessful" << endl; //aw dang it
            return ids;
        } else{
            for (const auto& id :  ids){
                cout<< id<< endl; // loop thru n print out each id cause multiple names
            }
            return ids;
        }

    }

    TreeNode* searchID (const string& id){  
        TreeNode* result = searchID(root, id);
        if (result) {
            cout << result->name << endl;
            return result;
        } else {
            cout << "unsuccessful" << endl;
            return nullptr;
        }   
    }  

    // DEBUGGING FUNCTIONS
    void printTreeStructure(TreeNode* node, int depth = 0) { // for debugging tree structure
        if (!node) return;
        
        printTreeStructure(node->right, depth + 1);
        
        for (int i = 0; i < depth; i++) cout << "  "; //aka height depth = height here 
        cout << node->ID << "(" << node->name << ")" << endl;
        
        printTreeStructure(node->left, depth + 1);
    }

    void debugPrintTree() {
        cout << "=== Tree Structure ===" << endl; //ayyy ok formating
        printTreeStructure(root);
        cout << "=====================" << endl;
    }
    void debugNodeContents() {
        cout << "=== Node Contents Debug ===" << endl; 
        debugNodeContentsHelper(root);
        cout << "===========================" << endl;
    } 
    void debugNodeContentsHelper(TreeNode* node) { //to solveissue of swapping name and ids 
        if (!node) return;
        debugNodeContentsHelper(node->left); // recurisive! we are a binary tree after all
        cout << "ID: '" << node->ID << "' | Name: '" << node->name << "'" << endl;
        debugNodeContentsHelper(node->right);
    }
};  