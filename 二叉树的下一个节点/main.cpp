#include <iostream>

using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};

class Solution {
public:
    TreeLinkNode* Find_Next(TreeLinkNode* head,TreeLinkNode* tail,TreeLinkNode*& cur){
        if(!head) return NULL;
        if(head->left){
           TreeLinkNode *tem;
           tem =  Find_Next(head->left,tail,cur);
           if(tem) return tem;
        }
        if(cur==tail) return head;
        else{
            cur = head;
        }
        return  Find_Next(head->right,tail,cur);
    }
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        //分两步走，找到一个根节点
        TreeLinkNode *head=pNode,*nNode=NULL;
        if(!head->next) head = pNode;
        else {
           while(head->next){
               head = head->next;
           }
        }
        //head节点是当前的根节点
        TreeLinkNode* cur=NULL;
        return Find_Next(head,pNode,cur);
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
