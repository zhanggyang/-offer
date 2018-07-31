#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//×Ö·û´®µÄÅÅÐò
bool com(char a,char b){
    return a<b;//ÉýÐòÅÅÁÐ
}

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> re;
        if(str.empty()) return re;
        sort(str.begin(),str.end(),com);
        re = Recursion(str);
        return re;
    }

    vector<string> Recursion(string str){
        vector<string> re;
        if(str.size()== 1) {
            re.push_back(str);
            return re;
        }
        char cur = str[0];
        vector<string> tem;
        tem = Recursion(str.substr(1));
        for(auto &c:tem){
            //c.insert(0,&cur,1);
            c.insert(0,1,cur);
            re.push_back(c);
        }

        for(int i=1;i<str.size();i++){
            if(str[i]!=cur){
                cur = str[i];
                str[i] = str[0];
                str[0] = cur;
                tem = Recursion(str.substr(1));
                for(auto &c:tem){
                c.insert(0,&cur,1);
               // c.insert(0,1,cur);
                re.push_back(c);
                }
            }
        }
        return re;
    }
};

int main()
{
    Solution m;
    vector<string> re;
    string str("aa");
    re = m.Permutation(str);
    cout<<re.size()<<endl;
    for(auto c:re){
        cout<<c<<endl;
    }
    return 0;

}
