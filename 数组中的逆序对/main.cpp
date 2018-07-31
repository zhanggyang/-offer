#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int MemeryArray(vector<int> a,vector<int> b,vector<int>& c){
        int i=0,j=0,k=0,sum=0;
        while(i<a.size() && j<b.size()){
            if(a[i]<b[j]) c[k++] = a[i++];
            else {
                c[k++] = b[i++];
                sum = sum + i + 1;
            }
        }
        while(i<a.size()) c[k++] = a[i++];
        while(j<b.size()) {
            c[k++] = b[j++];
            sum+=i;
        }
        return sum;

    }
    int InversePairs(vector<int>& data) {
        int sum = 0;
        if(data.size()<=1) return 0;
        if(data.size()==2) {
            if(data[0]>data[1]) {
               swap(data[0],data[1]);
               sum+=1;
            }
            return sum;
        };
        vector<int> left,right;
        left.assign(data.begin(),data.begin()+data.size()/2);
        sum+=InversePairs(left);
        right.assign(data.begin()+data.size()/2,data.end());
        sum+=InversePairs(right);
        //合并两个递增数组
        sum+=MemeryArray(left,right,data);
        return sum;
    }
};
int main()
{
    Solution m;
    vector<int> s ={1,2,3,4,5,6,7,0};
    cout<<m.InversePairs(s);
    return 0;

}
