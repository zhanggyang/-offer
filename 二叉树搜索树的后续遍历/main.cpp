#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(vector<int> &sequence,int left,int right){
        if(right-left<=2) return true;
        int mid = left;
        bool flag = true;
        for(int i=left;i<right;i++){
            if(sequence[i]<sequence[right]) {
                if(flag) return false;
                mid++;
            }
            else flag = true;
        }
        return dfs(sequence,left,mid-1) && dfs(sequence,mid,right-1);
    }
    bool VerifySquenceOfBST(vector<int> sequence){
         if(sequence.empty()) return false;
         return dfs(sequence,0,sequence.size()-1);
    }
    /*
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty()) return false;
        if(sequence.size()<=3) return true;
        vector<int> left,right;
        int key = sequence[sequence.size()-1];
        bool flag = false;
        for(int i=0;i<sequence.size()-1;i++){
            if(sequence[i]<key) {
                if(flag) return false;//左子树中不应该存在比根节点大的数
                left.push_back(sequence[i]);
            }
            else {
                flag = true;
                right.push_back(sequence[i]);
            }
        }
        return (left.empty()||VerifySquenceOfBST(left)) &&
                (right.empty()||VerifySquenceOfBST(right));
    }*/
};
int main()
{
    Solution m;
    vector<int> a = {1,2,3,4,5,6};
    bool f = m.VerifySquenceOfBST(a);
    cout << f << endl;
    return 0;
}
