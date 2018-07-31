#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
bool compare(const vector<int> &a,const vector<int> &b){
        return a.size()>b.size();//½»»»Ìõ¼þ
    }
class Solution {
public:
    void dfs(TreeNode* root,int num){
         tem.push_back(root->val);
         if(num-root->val == 0 &&  !root->left && !root->right)
            ans.push_back(tem);
         else{
            if(root->left) dfs(root->left,num-root->val);
            if(root->right) dfs(root->right,num-root->val);
            }
            tem.pop_back();

    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root) dfs(root,expectNumber);
        sort(ans.begin(),ans.end(),compare);
        return ans;
    }
private:
    vector<vector<int> > ans;
    vector<int> tem;
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
