#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > res;
        if(sum<3) return res;
        vector<int> nums;
        int tem = 0 ;
        for(int i=1;i<=(sum/2)+2;++i) nums.push_back(i);
        //for(auto i:nums) cout<<i;
        for(auto left = nums.begin(),right=nums.begin(),end = nums.end();right!=end && left!=end;){
            if(tem<sum) {
                tem+= *right;
                ++right;
            }
            else if(tem>sum){
                tem -= *left;
                ++left;
            }
            else {
                vector<int> t(left,right);
                res.push_back(t);
                tem+= *right;
                ++right;
            }
        }
        return res;
    }
};
int main()
{
    int sum =100;
    Solution m;
    vector<vector<int>> a(m.FindContinuousSequence(sum));

    cout << "Hello world!" << endl;
    return 0;
}
