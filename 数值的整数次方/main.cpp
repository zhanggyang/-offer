#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    double Power(double base, int exponent) {
    double ans = 1;
    bool flag = false;
    if(exponent==0) return 1;
    if(exponent<0){
        if(Equal(base,0.0)) return -1;
        exponent = -exponent;
        flag = true;
    }

    while(exponent){
        if((exponent&1)==1)
            ans *= base;
        base *=base;//指数运算的值相乘等于指数相加
        exponent>>=1;
    }
    if(flag) ans = double(1.0) /ans;
    return ans;

    }
    bool Equal(double x,double y){
        if((x-y)<0.00000001 && (x-y)>-0.00000001 ) return true;
        return false;
    }
};
int main()
{
    char a =12;
    int b = 12.0;
    int c = 12.0f;
    int d = (int)12.0;
    Solution m;
    cout <<m.Power(2,-3)<< endl;
    return 0;
}
