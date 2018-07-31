#include <iostream>
#include <string.h>
using namespace std;
class Solution {
public:
    bool isNumeric(char* string)
    {
        bool flag = true,e_flag = false,p_flag = true,n_flag = true;
        //去除前面的空格
        int len = strlen(string);
        int i = 0;
        while(i<len){
            if(string[i]==' ') ++i;
            else break;
        }
        while(i<len){
            if(string[i]=='+' || string[i] == '-'){
                if(flag == false) return false;
                flag = false;
            }
            else if(string[i] == 'E' || string[i] == 'e'){
                if(i==len-1) return false;
                if(e_flag==false) return false;
                p_flag = false;//不能出现小数点
                flag = true;//可以再出现+ -
                n_flag = false;//已经出现了e，遇到数字后e_flag不再改变
            }
            else if(string[i] == '.'){
                if(p_flag==false) return false;
                //小数点后面只运行出现数字
                flag = e_flag = p_flag = n_flag =false;
            }
            else if(string[i]>='0' && string[i]<='9'){
                if(n_flag==true) e_flag = true;//e可以出现了；
                n_flag = false;
            }
            else return false;
            ++i;
        }
        return true;
    }

};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
