using namespace std;

class TreeNode{
    public:
    int ID; // userID
    TreeNode *left; 
    TreeNode *right;    
    TreeNode(): ID(0), left(nullptr), right(nullptr){}
    TreeNode (int x) : ID (x), left(nullptr), right(nullptr){}
    TreeNode (int x, TreeNode *left, TreeNode *right): ID(x), left(left), right(right) {}

};

class Tree{
   public:
    TreeNode* root; //a pointer to the root!

    //i would like to put the insert, delete functions in here? 
    
};  