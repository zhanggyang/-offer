#include <iostream>
#include <vector>
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> re;
        if(!root) return re;
        vector<TreeNode*> qu;
        qu.push_back(root);

        for(int i = 0;i < qu.size();i++){
            if(qu[i]->left != NULL) qu.push_back(qu[i]->left);
            if(qu[i]->right != NULL) qu.push_back(qu[i]->right);
            re.push_back(qu[i]->val);
        }
        return re;
     }

};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
