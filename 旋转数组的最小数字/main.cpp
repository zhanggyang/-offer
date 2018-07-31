#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty()) return 0;
        int r = rotateArray.size();
        if(r==1) return rotateArray[0];


        int l=0,m;
        r--;

        while(l<r){//至少是两个

            if(rotateArray[l] < rotateArray[r]) return rotateArray[l]; //单调递增的
            m = (l+r)/2;
            if(rotateArray[m]>rotateArray[l]) {
               //去掉左边一半
               l = m + 1;
            }
            else if(rotateArray[m]<rotateArray[r]){
                //去掉右边一半
                r = m;
            }
            else {
                while(rotateArray[l] == rotateArray[m] && l < r ){
                    //左中右相等时，无法判断去掉那一半，找到第一个不等的,即为输出
                    l++;
                }


            }
        }

        return  rotateArray[l];

    }

};


int main()
{
    Solution s;
    vector<int> rotateArray = {0,1,1,1,1,1,1,5};
    int tem = s.minNumberInRotateArray(rotateArray);
    cout <<tem<< endl;
    return 0;
}
