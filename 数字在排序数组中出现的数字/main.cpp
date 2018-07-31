#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int Biserch_left(vector<int> data,int k){
        if(data.empty()) return -1;
        int left = 0,right = data.size()-1,mid=-1;

        while(left<=right){
            if(data[left] == k) return left;
            if(left==right) return -1;
            mid = (left+right)/2;
            if(data[mid]>k){
                right = mid-1;
            }
            else if(data[mid]>k){
                left = mid+1;
            }
            else right = mid;
        }
        return -1;//√ª’“µΩ
    }
    int Biserch_right(vector<int> data,int k){
        if(data.empty()) return -2;
        int left = 0,right = data.size()-1,mid = -1;
        while(left<=right){
            if(data[right] == k) return right;

            mid = (left+right+1)/2;
            if(data[mid]>k){
                right = mid-1;
            }
            else if(data[mid]>k){
                left = mid+1;
            }
            else left = mid;
        }
        return -2;
    }
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.empty()) return 0;
        return (Biserch_right(data,k)- Biserch_left(data,k)+1);
    }
};
int main()
{
    Solution m;
    vector<int> a = {1,2,3,3,4,5};
   // for(auto i : a) cout<<m.GetNumberOfK(a,i)<<" ";
    cout<<m.GetNumberOfK(a,2);
    //cout << "Hello world!" << endl;
    return 0;
}
