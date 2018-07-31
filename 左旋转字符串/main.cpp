#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string LeftRotateString(string str, int n)
    {
        if(n<=0 || str.empty()) return str;
        int len = str.size();
        n = n%len;
        string s(str);
        for(int i=0;i<len;i++){
            s[(i+len-n)%len] = str[i];
        }
        return s;
    }
    string LeftRotateString2(string str, int n)
    {
        if(str.empty()) return "";
        int len = str.size();
        if(len == 0) return "";
        n = n % len;
        str += str;
        return str.substr(n, len);
    }

};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
