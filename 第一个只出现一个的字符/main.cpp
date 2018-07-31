#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        map<char,int> mp;
        for(int i=0;i<str.size();i++){
            mp[str[i]]++;
        }
        for(int i=0;i<str.size();i++){
            if(mp[str[i]]==1)
                return i;
        }
        return -1;
    }
    /*
    int FirstNotRepeatingChar(string str) {
        vector<int> table(128,0);
        vector<int> position(128,-1);
        for(int i=0;i<str.size();i++){
            int tem = str[i] - 'A';
            if(table[tem]==0) {
               position[tem] = i;
               table[tem]=1;
            }
            else{
               position[tem] = -1;
            }
        }

        int M = str.size();
        bool flag = false;
        for(auto a:position){
            if(a!=-1) {
               M = min(M,a);
               flag = true;
            }
        }
        if(!flag) return -1;
        else return M;
    }*/
};

int main()
{
    Solution m;
    string str ="abcdabcZ";
    int pos = m.FirstNotRepeatingChar(str);
    cout<<pos;
    return 0;
}

