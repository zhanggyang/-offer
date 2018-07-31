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
    vector<vector<int> > Print(TreeNode* pRoot){
        vector<vector<int> > res;
        if(!pRoot) return res;
        vector<int> t;
        vector<TreeNode*> n;
        t.push_back(pRoot->val);
        res.push_back(t);
        n.push_back(pRoot);
        while(!n.empty()){
            vector<TreeNode*> tem(n);
            n.clear();
            t.clear();
            for(auto p : tem){
                if(p->left) {
                   n.push_back(p->left);
                   t.push_back(p->left->val);
                }
                if(p->right) {
                   n.push_back(p->right);
                   t.push_back(p->right->val);
                }
            }
            if(!t.empty()) res.push_back(t);
        }
        return res;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
