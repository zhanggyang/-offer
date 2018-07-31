#include <iostream>
using namespace std;


class Solution {
public:

    /*int NumberOf1(int n){
        int cnt = 0;
        while(n){
            n = n&(n-1); //每次去掉一个数的最后一个1
            cnt++;
        }
        return cnt;
    }*/
    int NumberOf1(int n){
        int cnt = 0;
        int flag = 1;
        while(flag){
            if(flag&n) cnt++;
            flag <<= 1;
        }
        return cnt;
    }

    /*
     int  NumberOf1(int n) {
         if(n==0) return 0;
         if(n==0x80000000) return 1;
         bool flag = false;
         int cnt_1 = 0,de = 0;
         if(n<0) {
            n=-n;
            flag = true;
         }

         bool tag = true;
         while(n){
             if(n%2) {cnt_1++;
                tag = false;
             }
             else {
                if(tag) de++;
             }

             n = n/2;
             }
         if(flag) cnt_1 = 32 - cnt_1-de+1;
         return cnt_1;

     }*/
};
int main()
{
    Solution a;
    for(int i=-2;i<10;i++) cout << a.NumberOf1(i) << endl;
    return 0;
}
