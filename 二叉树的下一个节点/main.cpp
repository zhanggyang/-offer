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
        //�������ߣ��ҵ�һ�����ڵ�
        TreeLinkNode *head=pNode,*nNode=NULL;
        if(!head->next) head = pNode;
        else {
           while(head->next){
               head = head->next;
           }
        }
        //head�ڵ��ǵ�ǰ�ĸ��ڵ�
        TreeLinkNode* cur=NULL;
        return Find_Next(head,pNode,cur);
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
