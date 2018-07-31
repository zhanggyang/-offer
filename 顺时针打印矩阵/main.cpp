#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> re;
        int ud = matrix.size();
        if(ud==0) return re;
        int lr = matrix[0].size();
        int left = 0,up = 0;//left��up��ʾ����ֵ
        int lr_len = lr,ud_len = ud;//���е�Ԫ�صĸ���������Ԫ�صĸ���
        int cnt = 0;//��������4ȡ������0,1,2,3���ֱ������������
        while(lr_len>1 || ud_len > 1){
            switch(cnt%4){
                case 0:
                {for(int i=0;i<lr_len;i++){
                    re.push_back(matrix[up][left]);
                    left++;
                }
                left--;//��left��λ
                up++;//ָ����һ��
                ud_len--;
                break;
                }
                case 1:
                {for(int i=0;i<ud_len;i++){
                     re.push_back(matrix[up][left]);
                     up++;
                }
                up--;
                left--;
                lr_len--;
                break;
                }
                case 2:
                { for(int i=0;i<lr_len;i++){
                    re.push_back(matrix[up][left]);
                    left--;
                    }
                    left++;
                    up--;
                    ud_len--;
                    break;
                }
                case 3:{
                    for(int i=0;i<ud_len;i++){
                        re.push_back(matrix[up][left]);
                        up--;
                    }
                    up--;
                    left++;
                    lr_len--;
                    break;
                }
            }
            cnt++;
        }
        return re;

    }
};

int main()
{
    vector<vector<int> > matrix(4, vector<int>(4, 0));
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            matrix[i][j] = 4*i+j+1;
        }
    }

//    for(int i=0;i<4;i++){
  //      for(int j=0;j<4;j++){
    //       cout<<matrix[i][j]<<" ";
      //  }
    //}
    cout<<endl;
    Solution m;
    vector<int> c;
    c = m.printMatrix(matrix);
    for(int i=0;i<c.size();i++) cout<<c[i]<<" ";
    return 0;
}
