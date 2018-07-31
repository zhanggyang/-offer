#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        //if(pushV.empty()) return true;
        stack<int> m;

        int p1 = 0,p2=0;

        while(p1 < pushV.size()){
            m.push(pushV[p1]);
            p1++;
            while(!m.empty()){
                if(m.top() == popV[p2]){
                    m.pop();
                    p2++;
                }
                else break;
            }
        }

        return m.empty();

    }
};
int main()
{
    vector<int> pushV = {1,2,3,4,5} ,popV = {4,3,5,1,2};
    Solution m;
    cout <<  m.IsPopOrder(pushV,popV)<< endl;
    return 0;
}
