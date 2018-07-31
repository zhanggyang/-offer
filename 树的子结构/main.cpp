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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot2 == NULL) return false;
        return help(pRoot1,pRoot2);

    }
    bool help(TreeNode* pRoot1, TreeNode* pRoot2){
        if(pRoot2 == NULL) return true;
        if(pRoot1 == NULL) return false;
        if(pRoot1->val == pRoot2->val)
            return (help(pRoot1->left,pRoot2->left) && help(pRoot1->right,pRoot2->right))
                    || help(pRoot1->left,pRoot2) || help(pRoot1->right,pRoot2);
        else return help(pRoot1->left,pRoot2) || help(pRoot1->right,pRoot2);
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
