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
    void convert(TreeNode* Node,TreeNode* &last){
        //last��Ҫ���ӵ�ǰ�ڵ�����Ӧ������������ߵĽڵ�
        //last���ָ��ǰ�ڵ�����Ӧ�����������ұߵĽڵ�
        if(Node == NULL) return;

        if(Node->left){
           convert(Node->left,last);
        }
        Node->left = last;
        if(last) last->right = Node;
        last = Node;
        if(Node->right){
          convert(Node->right,last);
        }


    }
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL) return pRootOfTree;
        TreeNode *last =NULL;
        convert(pRootOfTree,last);
        while(last->left){
            last = last->left;
        }
        return last;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
