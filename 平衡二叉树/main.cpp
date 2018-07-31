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
    bool IsBalanced(TreeNode* pRoot,int& depth)
    {
        if(!pRoot) return true;
        depth+=1;
        int left=depth,right =depth;
        if(!IsBalanced(pRoot->left,left)) return false;
        if(!IsBalanced(pRoot->right,right)) return false;
        if (left-right>1 || right-left>1) return false;
        depth = max(left,right);
        return true;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int depth = 0;
        return IsBalanced(pRoot,depth);

    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
