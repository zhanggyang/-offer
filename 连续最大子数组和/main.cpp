#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        vector<int> Dp(array.size(),0);
        Dp[0] = array[0];
        int Max = array[0];
        for(int i=1;i<array.size();i++){
            if(Dp[i-1]<=0) Dp[i] = array[i];
            else Dp[i] = Dp[i-1]+array[i];
            Max =max(Dp[i],Max);
        }
        return Max;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
