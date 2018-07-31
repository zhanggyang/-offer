#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size()== 2){
            *num1 = data[0];
            *num2 = data[1];
            return ;
        }
        //
        int sum = 0;
        for(auto i : data) sum ^= i;//������ͬ�������ֵ
        //�Ҵ��һ��1
        int tem = 1;
        while((tem & sum)==0) tem = tem<<1;//��һ����ͬ�ĵ�λ
        //�������Ϊ����
        *num1 = 0;*num2=0;
        for(auto i : data) {
            if((i&tem)==0) (*num1) ^= i;
            else (*num2) ^=i;
        }
        return ;
    }
};
int main()
{
    vector<int> data ={2,4,3,6,3,2,5,5};
    int num1,num2;
    Solution m;
    m.FindNumsAppearOnce(data,&num1,&num2);
    cout << num1 << num2<< endl;
    return 0;
}
