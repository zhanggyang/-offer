#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> res;
        if(array.size()<2) return res;
        int left = 0,right = array.size()-1;
        while(left<right){
            if(array[left]+array[right] == sum ){
                res.push_back(array[left]);
                res.push_back(array[right]);
                return res;
            }
            else if(array[left]+array[right] > sum){
                right--;
            }
            else left++;
        }
        return res;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
