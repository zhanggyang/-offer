#include <iostream>
#include <string.h>
using namespace std;
class Solution {
public:
    bool isNumeric(char* string)
    {
        bool flag = true,e_flag = false,p_flag = true,n_flag = true;
        //ȥ��ǰ��Ŀո�
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
                p_flag = false;//���ܳ���С����
                flag = true;//�����ٳ���+ -
                n_flag = false;//�Ѿ�������e���������ֺ�e_flag���ٸı�
            }
            else if(string[i] == '.'){
                if(p_flag==false) return false;
                //С�������ֻ���г�������
                flag = e_flag = p_flag = n_flag =false;
            }
            else if(string[i]>='0' && string[i]<='9'){
                if(n_flag==true) e_flag = true;//e���Գ����ˣ�
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
