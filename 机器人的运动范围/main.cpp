#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if(threshold<0) return 0;
        //vector<int> tem(0,cols);
        vector<vector<int>> dp(rows,vector<int>(cols,0));
        //for(int i=0;i<)
        //int **  dp = new int [rows] [cols] ;
        //memset(dp,false,rows*cols)；
        dp[0][0] = 1;//判断当前的点是不是可达的
        int cnt = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(dp[i][j] && reach(threshold,i,j)){
                    ++cnt;
                    if(i>0) dp[i-1][j] = 1;
                    if(j>0) dp[i][j-1] = 1;
                    if(j<rows-1) dp[i][j+1] = 1;//当前点符合条件
                    if(i<cols-1) dp[i+1][j] = 1;
                }
            }
        }
        return cnt;
    }

    bool reach(int th,int rows,int cols){
        int sum = 0;
        while(rows){
            sum += rows%10;
            rows = rows/10;
        }
        while(cols){
            sum += cols%10;
            cols = cols/10;
        }
        if(sum < th) return true;
        else return false;
    }
};
int main()
{
    Solution m;
    int c = m.movingCount(5,10,10);

    cout << c << endl;
    return 0;
}
