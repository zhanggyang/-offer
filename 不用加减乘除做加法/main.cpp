#include <iostream>

using namespace std;
class Solution {
public:
    int Add(int num1, int num2)
    {
        int tem;
        while(num2){
            tem = num1^num2;//��λ��
            num2 = (num1&num2)<<1;//��λ
            num1 = tem;
            //ֱ����������λ
        }
        return num1;
    }
};
int main()
{
    Solution m;
    cout << m.Add(10,21) << endl;
    return 0;
}


// ����Ϊ���Ե��ж�����������淶ʾ���������ύ�����Ʒ֡�
