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
            //cur��ǰһ���ڵ�
        }
        return (cur-1+n)%n;
        //��һ����δ���ҵ�
    }
};
int main()
{
    Solution m;
    cout<<m.LastRemaining_Solution(6,6);

    //cout << "Hello world!" << endl;
    return 0;
}
