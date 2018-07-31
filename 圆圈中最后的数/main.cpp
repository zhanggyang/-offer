#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        vector<int> num(n,1);
        int cnt = n,cur = 0,time = (m-1)%n;
        while(cnt){
            time = (m-1)%cnt;
            while(time>=0){
                if(num[cur]) {
                    if(time==0) num[cur] = 0;
                    --time;
                }
                cur = (cur+1)%n;
            }
            cnt--;
            //cur的前一个节点
        }
        return (cur-1+n)%n;
        //有一个人未被找到
    }
};
int main()
{
    Solution m;
    cout<<m.LastRemaining_Solution(6,6);

    //cout << "Hello world!" << endl;
    return 0;
}
