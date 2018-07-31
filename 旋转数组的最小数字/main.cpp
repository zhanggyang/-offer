#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty()) return 0;
        int r = rotateArray.size();
        if(r==1) return rotateArray[0];


        int l=0,m;
        r--;

        while(l<r){//����������

            if(rotateArray[l] < rotateArray[r]) return rotateArray[l]; //����������
            m = (l+r)/2;
            if(rotateArray[m]>rotateArray[l]) {
               //ȥ�����һ��
               l = m + 1;
            }
            else if(rotateArray[m]<rotateArray[r]){
                //ȥ���ұ�һ��
                r = m;
            }
            else {
                while(rotateArray[l] == rotateArray[m] && l < r ){
                    //���������ʱ���޷��ж�ȥ����һ�룬�ҵ���һ�����ȵ�,��Ϊ���
                    l++;
                }


            }
        }

        return  rotateArray[l];

    }

};


int main()
{
    Solution s;
    vector<int> rotateArray = {0,1,1,1,1,1,1,5};
    int tem = s.minNumberInRotateArray(rotateArray);
    cout <<tem<< endl;
    return 0;
}
