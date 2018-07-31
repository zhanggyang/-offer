#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    bool Symmetrical(TreeNode* left,TreeNode *right){
        if(!left){
            if(!right) return true;
            else return false;
        }
        if(!right) return false;
        return left->val == right->val && Symmetrical(left->right,right->left) && Symmetrical(left->left,right->right);
    }
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(!pRoot) return true;
        if(!pRoot->left){
            if(!pRoot->right) return true;
            else return false;
        }
        if(!pRoot->right) return false;
        return Symmetrical(pRoot->left,pRoot->right);
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
