#include <iostream>

using namespace std;
class Solution {
public:
    int Add(int num1, int num2)
    {
        int tem;
        while(num2){
            tem = num1^num2;//本位和
            num2 = (num1&num2)<<1;//进位
            num1 = tem;
            //直到不产生进位
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


// 本题为考试单行多行输入输出规范示例，无需提交，不计分。
