#include <iostream>
#include <queue>
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
    int TreeDepth(TreeNode* pRoot)
    {
      //return  (!pRoot)?  0 : max(TreeDepth(pRoot->left),TreeDepth(pRoot->right))+1;
        if(!pRoot) return 0;
        int left = TreeDepth(pRoot->left);
        int right =TreeDepth(pRoot->right);
        return max(left,right)+1;
    }
    int TreeDepth2(TreeNode* pRoot)
    {
        //非递归写法
        int depth = 0;
        if(!pRoot) return depth;
        queue<TreeNode*> q;
        q.push(pRoot);
        while(!q.empty()){
            int len = q.size();
            depth++;
            for(int i=0;i<len;i++){
                //删除一层节点，并将该层节点的孩子入栈
                TreeNode *tem = q.front();
                q.pop();
                if(tem->left) q.push(tem->left);
                if(tem->right) q.push(tem->right);
            }

        }
        return depth;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
