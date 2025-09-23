

using namespace std;

class TreeNode{
    public:
    int val; 
    TreeNode *left; 
    TreeNode *right;    
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode (int x) : val (x), left(nullptr), right(nullptr){}
    TreeNode (int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}

};

class Tree{
   public:
    TreeNode* root; //a pointer to the root!

    //i would like to put the insert, delete functions in here? 
    
};  