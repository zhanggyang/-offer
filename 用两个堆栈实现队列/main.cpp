#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    void push(int node) {
        if(stack1.empty()){
            //��stack2ջ��Ԫ��ת�Ƶ�stack1��
            while(!stack2.empty()){
                stack1.push(stack2.top());
                stack2.pop();
            }
        }
        stack1.push(node);

    }

    int pop() {
        if(stack2.empty()){
            //��stack1ջ��Ԫ��ת�Ƶ�stack2��
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int tem = stack2.top();
        stack2.pop();
        return tem;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main()
{

    cout << "Hello world!" << endl;
    return 0;
}
