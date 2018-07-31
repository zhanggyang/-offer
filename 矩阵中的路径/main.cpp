#include <iostream>
#include <mem.h>
using namespace std;
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(matrix==NULL || rows < 1 || cols < 1 || str == NULL)
            return false;
        bool *flag = new bool[rows*cols];
        memset(flag,true,rows*cols);
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(help(matrix,rows,cols,i,j,str,0,flag))
                    return true;
            }
        }
        delete[] flag;
        return false;
    }

    bool help(char* matrix,int rows,int cols,int i,int j,char* str,int k,bool* flag){
        int index = i*cols + j;
        if(index >= strlen(matrix) || flag[index] == false || matrix[index] != str[k] ) return false;
        if(str[k+1]=='\0') return true;//已经找到路径
        flag[index] = false;
        if(help(matrix,rows,cols,i+1,j,str,k+1,flag) ||
           help(matrix,rows,cols,i-1,j,str,k+1,flag) ||
           help(matrix,rows,cols,i,j+1,str,k+1,flag) ||
           help(matrix,rows,cols,i,j-1,str,k+1,flag)
          )
        return true;
        else flag[index] = true;//恢复现象
        return false;
    }

};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
