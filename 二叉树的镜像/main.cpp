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
    void Mirror(TreeNode *pRoot) {
        if(!pRoot) return;
        swap(pRoot->left,pRoot->right);
        Mirror(pRoot->left);
        Mirror(pRoot->right);
        //if(pRoot->left) Mirror(pRoot->left);
        //if(pRoot->right) Mirror(pRoot->right);
        return ;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
