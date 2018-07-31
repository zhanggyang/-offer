#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    void Reverse(string& str,int i,int j)
    {
        while(i<j){
            swap(str[i++],str[j--]);
        }
        return;
    }
    string ReverseSentence(string str)
    {
        if(str.empty()) return str;
        int len = str.size()-1;
        Reverse(str,0,len);
        cout<<str;
        int left = 0,right = 0;
        for(int i = 0;i<=len;i++){
            if(str[i] == ' ') continue;
            else {
                left = i;right=i;
                while(i<=len && str[i]!=' '){
                    ++right;
                    ++i;
                }
                Reverse(str,left,right-1);
            }
        }
        return str;
    }
};
int main()
{
    string str = "I am a student.";
    Solution m;
    string s(m.ReverseSentence(str));
    cout << s << endl;
    return 0;
}
