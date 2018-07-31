#include <iostream>
#include <string>
#include <string.h>
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
    char* Serialize(TreeNode *root) {
        if(!root) return NULL;
        string str;
        Serialize(root, str);
        int len = str.length();
        char *res = new char[len+ 1];
        for(int i = 0; i < str.length(); ++i) res[i] = str[i];
        res[len] = '\0';
        return res;
    }
    void Serialize(TreeNode *root,string& str){
        if(!root){    str+='#'; return;}
        str += to_string(root->val);
        str +=',';
        Serialize(root->left, str);
        Serialize(root->right, str);
    }
    TreeNode* Deserialize(char *str){
        if(strlen(str) == 0) return NULL;
        return Deserialize1(str);
    }
    TreeNode* Deserialize1(char*& str){
        if(str[0]=='#'){
            ++str;
            return NULL;
        }
        int sum = 0;
        while(*str != '\0' && *str != ','){
            sum = sum*10 + (*str);
            ++str;
        }
        TreeNode *root = new TreeNode(sum);
        if(*str == '\0') return root;
        root->left = Deserialize1(str);
        root->right = Deserialize1(str);
        return root;
    }
};
int main()
{
    char str[] ={30,10,50,'#','#','#',20,45,'#','#',35,'#','#','\0'};
    Solution m;
    TreeNode* head= m.Deserialize(str);
    char *p = m.Serialize(head);
    while(*p != '\0') {
        cout<<(*p);
        p++;
    }
    //cout << "Hello world!" << endl;
    return 0;
}
