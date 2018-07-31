#include <iostream>
using namespace std;
class Solution {
public:
    int Fibonacci(int n) {
        if(n<=0) return 0;
        if(n==1 || n==2) return 1;
        int a =1,b=1;
        for(int i=2;i<n;i++){
            b = a+b;
            a = b-a;
        }
        return b;
    }
};
int main()
{
    Solution a;
    for(int i = 1;i<5;i++) cout<<a.Fibonacci(i)<<endl;
}
