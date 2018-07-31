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
        //三步法
        //复制并插入节点
        if(!pHead) return NULL;
        RandomListNode *currNode  = pHead;
        while(currNode){
            RandomListNode* node  = new RandomListNode(currNode->label);
            node->next = currNode->next;
            currNode->next = node ;
            currNode = node->next;
        }
        //设置random指针
        currNode = pHead;
        while(currNode){
            RandomListNode *node = currNode->next;
            if(currNode->random){
                node->random = currNode->random->next;
            }
            currNode = node->next;
        }

        //拆分
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




