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
        int left = 0,up = 0;//left，up表示列行值
        int lr_len = lr,ud_len = ud;//该行的元素的个数，该列元素的个数
        int cnt = 0;//计数，对4取余数，0,1,2,3，分别代表右下左上
        while(lr_len>1 || ud_len > 1){
            switch(cnt%4){
                case 0:
                {for(int i=0;i<lr_len;i++){
                    re.push_back(matrix[up][left]);
                    left++;
                }
                left--;//将left回位
                up++;//指向下一列
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
