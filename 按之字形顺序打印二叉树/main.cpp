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
        bool flag = true;
        while(!n.empty()){
            vector<TreeNode*> tem(n);
            n.clear();
            t.clear();
            for(auto p : tem){
                if(p->left)  n.push_back(p->left);
                if(p->right) n.push_back(p->right);
                //�������ڵ�
            }
            if(flag) {
                //�������
                for(int i =n.size()-1;i>=0;i--)  t.push_back(n[i]->val);
            }
            else{
                //�������
                for(auto i:n) t.push_back(i->val);
            }
            flag =!flag;//�ı䷽��

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
