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
    int Size(TreeNode* pRoot){
        if(!pRoot) return 0;
        else return Size(pRoot->left) + Size(pRoot->right) + 1;
    }
    TreeNode* Findk(TreeNode* pRoot,int& k){
        if(!pRoot) return NULL;
        TreeNode* re = NULL;
        re = Findk(pRoot->left,k);
        if(re) return re;
        if(k==1) return pRoot;
        else{
            --k;
            return Findk(pRoot->right,k);
        }
    }
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        //先计算节点的个数
        int len = Size(pRoot);
        if(k>len || k<1) return NULL;
        return Findk(pRoot,k);
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
