#include<iostream>
#include<vector>
using namespace std;


struct ListNode {
       int val;
       struct ListNode *next;
       ListNode(int x) :
             val(x), next(NULL) {
       }
 };

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == NULL) return pHead2;
        if(pHead1 == NULL) return pHead1;

        ListNode *re = new ListNode(0);
        ListNode* tem = re;

        while(pHead1!=NULL && pHead2!=NULL){
            if(pHead1->val > pHead2->val){
                tem->next = pHead2;
                pHead2 = pHead2->next;
                tem = tem->next;
            }
            else{
                tem->next = pHead1;
                pHead1 = pHead1->next;
                tem = tem->next;
            }
        }
        if(pHead1 == NULL) tem->next = pHead2;
        else tem->next = pHead1;

        return re->next;
     }
};

int main(){
	ListNode *h = new ListNode(0);
	h->val = 0;
	cout<<h->val;
	ListNode *head = h;
	for(int i = 1;i<10;i++){
		ListNode *tem = new ListNode(0);
        tem->val = i;
		head->next = tem;
		head=head->next;
		cout<<head->val;
	}
	head =NULL;
	Solution m;
    //vector<int> s = m.printListFromTailToHead(h);
//	for(int i=0;i<10;i++)  cout<<s[i]<<endl;
	return 0;

}
