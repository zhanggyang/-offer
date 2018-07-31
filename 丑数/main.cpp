#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index<=0) return 0;
        vector<int> UglyNumber(index,0);
        UglyNumber[0] = 1;
        int M2 = 0,M3 = 0,M5 = 0;
        for(int i=1;i<index;i++){
            UglyNumber[i] = min(min(UglyNumber[M2]*2,UglyNumber[M3]*3),UglyNumber[M5]*5);
            while(UglyNumber[M2]*2<=UglyNumber[i]) M2++;
            while(UglyNumber[M3]*3<=UglyNumber[i]) M3++;
            while(UglyNumber[M5]*5<=UglyNumber[i]) M5++;
        }
        return UglyNumber[index-1];
    }

};
int main()
{
    Solution m;
    for(int i=1;i<15;i++){
        cout<<m.GetUglyNumber_Solution(i)<<" ";
    }
    return 0;
}
