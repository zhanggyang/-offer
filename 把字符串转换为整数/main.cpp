#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int StrToInt(string str) {
        if(str.empty()) return 0;
        int pos=0;
        int len = str.size();
        long sum=0;
        bool tag = false;
         //去除前面的空格
        while(pos<len){
            if(str[pos]==' ') ++pos;
            else break;
        }
        if(pos>=len) return 0;

        if(str[pos]=='+'){++pos;}
        else if(str[pos]=='-'){
            tag = true;
            ++pos;
        }
        else if('0'<=str[pos]<='9'){
            sum = str[pos]-'0';
            ++pos;
        }
        else return 0;
        //计算数值
        while(pos<len){
            if(str[pos]<='9' && str[pos]>='0') sum = 10*sum + str[pos]-'0';
            else return 0;
            ++pos;
        }
        if(tag) sum = -sum;
        int m1 = 0x7fffffff;
        int m2 = 0x80000000;
        if(sum>m1 || sum<m2) return 0;
        return sum;
    }
};
int main()
{
    string s = "1a33";
    Solution m ;
    int a = m.StrToInt(s);
    cout << a<< endl;
    return 0;
}
