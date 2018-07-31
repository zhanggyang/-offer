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
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(!pHead) return pHead;
        ListNode *left  ,*right = pHead;
        bool flag = false;
        ListNode* head = new ListNode(0);
        head->next = pHead;
        left = head;
        while(right){
            bool flag = false;
            while(right->next && (right->val == right->next->val) ){
                right = right->next;
                flag = true;
            }
            if(flag){
                if(right->next) left->next = right->next;
                else left->next = NULL;
                right = right->next;
            }
            else{
                 right = right->next;
                 left = left->next;
            }

        }

        return head->next;
    }
};

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(!pHead) return pHead;
        ListNode *left =pHead ,*right = pHead->next;
        bool flag = false;
        while(left && right){
            //开始去重
            if(left->val != right->val){
                if(flag) {
                   flag = false;
                   pHead = right;
                   right = right->next;
                   left = left->next;
                }
                else {
                   pHead = left;
                   break;
                }
            }
            else {
                flag = true;
                right = right->next;
                left = left->next;
                pHead = right;
            }
        }

        while(right){
            bool flag = false;
            while(right->next && (right->val == right->next->val) ){
                right = right->next;
                flag = true;
            }
            if(flag){
                if(right->next) left->next = right->next;
                else left->next = NULL;
                right = right->next;
            }
            else{
                 right = right->next;
                 left = left->next;
            }

        }

        return pHead;
    }
};*/
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
