#include <iostream>
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
    ListNode* ReverseList(ListNode* head) {
        if(head == NULL) return head;
        //����ת��
        ListNode *h = new ListNode(0);
        ListNode *s;

        h->next = head;
        s = head->next;
        head->next = NULL;
        head = s;

        while(head!=NULL){
            s = head->next;//ʣ������ĵ�һ�ڵ�
            head->next = h->next;//ͷ�巨
            h->next = head;//ͷ���ָ������Ԫ��
            head=s;//ָ����λ
        }
        return h->next;
    }
};
int main()
{
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

    cout << "Hello world!" << endl;
    return 0;
}
