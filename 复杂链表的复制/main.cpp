#include <iostream>
using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        //������
        //���Ʋ�����ڵ�
        if(!pHead) return NULL;
        RandomListNode *currNode  = pHead;
        while(currNode){
            RandomListNode* node  = new RandomListNode(currNode->label);
            node->next = currNode->next;
            currNode->next = node ;
            currNode = node->next;
        }
        //����randomָ��
        currNode = pHead;
        while(currNode){
            RandomListNode *node = currNode->next;
            if(currNode->random){
                node->random = currNode->random->next;
            }
            currNode = node->next;
        }

        //���
        RandomListNode *pCloneHead = pHead->next;
        RandomListNode *tmp;
        currNode = pHead;
        while(currNode->next){
            tmp = currNode->next;
            currNode->next =tmp->next;
            currNode = tmp;
        }
        return pCloneHead;
    }
};

int main(){
  return 0;
}




