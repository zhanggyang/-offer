#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    void push(int node) {
        if(stack1.empty()){
            //将stack2栈中元素转移到stack1中
            while(!stack2.empty()){
                stack1.push(stack2.top());
                stack2.pop();
            }
        }
        stack1.push(node);

    }

    int pop() {
        if(stack2.empty()){
            //将stack1栈中元素转移到stack2中
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
