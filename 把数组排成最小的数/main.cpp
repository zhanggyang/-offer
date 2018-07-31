#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool com(string a,string b){

    //return (a+b)<(b+a);//ÉýÐò
    if(a.empty()) return true;
    if(a.size()>b.size()) return !com(b,a);
    int i=0;
    for(i=0;i<a.size();i++){
        if(a[i]>b[i]) return false;
        else if(a[i]<b[i]) return true;
    }
    b = b.substr(i);
    return com(a,b);


}

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        //int ×ªstring
        vector<string> nums;
        for(auto a :numbers)
            nums.push_back(to_string(a));
        sort(nums.begin(),nums.end(),com);
        string s;
        for(auto m :nums) s+=m;
        return s;
        }
};

int main()
{
    vector<int> m = {3,32,321};
    Solution k;
    string s = k.PrintMinNumber(m);
    cout << s << endl;
    return 0;
}
