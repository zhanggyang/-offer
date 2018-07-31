#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        //—°‘Ò≈≈–Ú
        vector<int> re;
        if(input.size()<k || input.empty()) return re;

        for(int i = 0;i<k;i++){
            int m = i;
            for(int j=i;j<input.size();j++){
                if(input[m]>input[j]) m = j;
            }
            if(m!=i) swap(input[i],input[m]);
            re.push_back(input[i]);
        }

        return re;
    }
};

int main()
{
    vector<int> a = {4,5,1,6,2,7,3,8};

    Solution m;
    vector<int> res = m.GetLeastNumbers_Solution(a,4);
    for(auto x:res)
    cout << x << " ";
    return 0;
}
