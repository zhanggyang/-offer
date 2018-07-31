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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode *p1 = pHead1,*p2 = pHead2;
        int len1 = 0,len2 =0;
        while(p1) {len1++;p1=p1->next;}
        while(p2) {len2++;p2=p2->next;}
        p1 = pHead1;
        p2 = pHead2;
        while(len1>len2) {p1 = p1->next;len1--;}
        while(len2>len1) {p2 = p2->next;len2--;}

        while(p1){
            if(p1==p2) return p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        return NULL;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
