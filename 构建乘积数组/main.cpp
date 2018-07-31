#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> tem;
        vector<int> res;
        int y = 1;
        int len = A.size();
        if(len<2) return res;
        for(int i = len-1;i>=1;--i){
            //fan
            y = y*A[i];
            tem.push_back(y);
        }
        //
        int t_len = tem.size()-1;
        res.push_back(tem[t_len]);
        y = A[0];
        for(int i=1;i<t_len;++i){
            res.push_back(y*tem[t_len-i]);
            y = y*A[i];
        }
        res.push_back(y);
        return res;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
