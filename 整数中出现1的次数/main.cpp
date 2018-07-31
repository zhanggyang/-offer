#include <iostream>
using namespace std;
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if(n<1) return 0;
        int sum = 0,cnt = 1,h=0,tem=0;
        //cnt当前位数的排列组合
        while(n){
            int y = n%10;
            if(n%10==0) sum = sum;
            else if(n%10==1) sum = h*cnt/10 + tem+1 + sum ;
            else sum = cnt + sum +h*y*(cnt/10) ;
            tem = tem+y*cnt;
            cnt = 10*cnt;
            n = n/10;
            h++;
        }
        return sum;
    }
    int NumberOf1Between1AndN_Solution2(int n)
    {
        int ones = 0;
        for(int m=1;m<=n;m*=10){
            ones += (n/m + 8) / 10 * m + (n/m % 10 == 1) * (n%m + 1);
        }
        return ones;
    }
};

int main()
{
    Solution m ;
    int re = m.NumberOf1Between1AndN_Solution(21345);
    cout<<m.NumberOf1Between1AndN_Solution2(5)<<" ";
    cout<<m.NumberOf1Between1AndN_Solution2(45)<<" ";
    cout<<m.NumberOf1Between1AndN_Solution2(345)<<" ";
    cout<<m.NumberOf1Between1AndN_Solution2(1345)<<" ";
    cout<<m.NumberOf1Between1AndN_Solution2(21345)<<" ";
    return 0;
}
