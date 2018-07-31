#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        int Min = 14,Max = 0,cnt = 0;
        for(auto k : numbers){
            if(k==0) ++cnt;
            else{
                Min = min(k,Min);
                Max = max(k,Max);
            }
        }
        if(Max-Min<4-cnt) return false;//一定存在对子
        if(Max-Min>=5) return false;//太长了
        return true;
    }
};
int main()
{
    vector<int> a ={1,3,4,5,2};
    Solution m;
    m.IsContinuous(a);
    return 0;
}
