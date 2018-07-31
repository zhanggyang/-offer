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
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> re;
        if(head == NULL) return re;
        //Á´±í×ªÖÃ
        ListNode h = ListNode(0);
        ListNode *s;

        h.next = head;
        s = head->next;
        head->next = NULL;
        head = s;

        while(head!=NULL){
            s = head->next;
            head->next = h.next;
            h.next = head;
            head=s;
        }

        s = h.next;
        while(s!=NULL){
            re.push_back(s->val);
            s=s->next;
        }
        return re;
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
	vector<int> s = m.printListFromTailToHead(h);
	for(int i=0;i<10;i++)  cout<<s[i]<<endl;
	return 0;

}
