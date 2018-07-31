#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        //一次遍历
        ListNode *first = pListHead,*last = pListHead;

        while(first != NULL){
              if(k==1){
               //cout<<first->val;
                 first = first->next;
                 if(first!=NULL) last=last->next;
              }
              else{//first先走k-1次，当first->next非空时才有效
                    first=first->next;
                    if(first!=NULL) k--;//计数
              }
        }
        //cout<<last->val;
        if(k>1) return NULL;//链表不够长
        else return last;
    }
};

int main()
{
   ListNode *h = new ListNode(0);
	h->val = 1;
	cout<<h->val;
	ListNode *head = h;
	for(int i = 2;i<6;i++){
		ListNode *tem = new ListNode(0);
        tem->val = i;
		head->next = tem;
		head=head->next;
		cout<<head->val;
	}
	head =NULL;
	Solution m;
	//for(unsigned int i=1;i<5;i++){
        //cout << (m.FindKthToTail(h,6))->val << endl;
	//}

    return 0;
}
