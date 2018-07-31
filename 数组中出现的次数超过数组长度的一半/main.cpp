#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution( vector<int> numbers){
        if(numbers.empty()) return 0;
        if(numbers.size()==1) return numbers[0];
        int len = (numbers.size()+1)/2;
        for(int i=0;i<=len;i++){
            int sum = 1;
            for(int j=i+1;j<numbers.size();j++)
                if(numbers[i]==numbers[j]) {
                    sum++;
                    if(sum*2>numbers.size()) return numbers[i];
                }
        }

        return 0;

    }
};
int main()
{
    vector<int> a = {2};

    Solution m;
    int res = m.MoreThanHalfNum_Solution(a);
    cout << res << endl;
    return 0;
}
