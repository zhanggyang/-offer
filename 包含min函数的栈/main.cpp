#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    void push(int value) {
        s1.push(value);
        if(s2.empty() || value<s2.top()) s2.push(value);
        else s2.push(s2.top());
    }
    void pop() {
        if(!s1.empty()){
            s1.pop();
            s2.pop();
        }

    }
    int top() {
        assert(s1.size()>0 && s2.size()>0)
        return s1.top();
    }
    int min() {
        assert(s1.size()>0 && s2.size()>0)
        return s2.top();
    }
    private :
    stack<int> s1;
    stack<int> s2;
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
