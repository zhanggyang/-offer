#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {

        if(pre.empty()) return NULL;
        TreeNode *Node = new TreeNode(pre[0]);
        vector<int> l_pre,l_vin,r_pre,r_vin;

        //直接分片
        //获取分片的位置
        bool flag = true;
        for(auto v=vin.begin(),p=pre.begin();v!=vin.end();v++,p++){
            if(*v == pre[0]){
                flag = false;
                continue;
            }
            if(flag){
            //生成左子树的参数
               l_pre.push_back(*(p+1));
               l_vin.push_back(*v);
            }
            else{
                r_pre.push_back(*p);
                r_vin.push_back(*v);
            }
        }

        //构造子树
        Node->left = reConstructBinaryTree(l_pre,l_vin);
        Node->right = reConstructBinaryTree(r_pre,r_vin);
        return Node;
    }

};
void lprint(TreeNode *T){
        if(T == NULL) return;
        lprint(T->left);
        cout<<T->val<<" ";
        lprint(T->right);
    }
void print(TreeNode *T){
        if(T == NULL) return;
        cout<<T->val<<" ";
        print(T->left);
        print(T->right);
    }

int main()
{
    vector<int> pre = {1,2,4,7,3,5,6,8},vin = {4,7,2,1,5,3,8,6};
    Solution s;
    TreeNode*  N =s.reConstructBinaryTree(pre,vin);
    print(N);
    cout<<endl;
    lprint(N);
    return 0;
}
