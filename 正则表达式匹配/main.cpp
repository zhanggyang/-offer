#include <iostream>
#include <string.h>
using namespace std;
class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if(strlen(str)==0){
            if(strlen(pattern) == 0) return true;
            else if(strlen(pattern)>=2 && pattern[0] != '*' && pattern[1] == '*') return match(str,pattern+2);
            else  return false;
        }
        else if(strlen(pattern) == 0) return false;

        else if((str[0]==pattern[0] || pattern[0] == '.')) {
            if(strlen(pattern)==1) return strlen(str)==1; //str未匹配玩
            if(pattern[1]!='*') return match(str+1,pattern+1);
            return match(str+1,pattern+2) ||  match(str+1,pattern) || match(str,pattern+2);//匹配1次，多次和0次
        }
        return false;

    }
};
int main()
{
    //double s = 13e;
    cout << "Hello world!" << endl;
    return 0;
}
