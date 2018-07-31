#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
     void reOrderArray(vector<int> &array) {
       //√∞≈›≈≈–Ú
       for(int i=0;i<array.size();i++){
            for(int j=array.size()-1;j>i;j--){
                if(array[j]%2==1 && array[j-1]%2==0){
                    array[j] +=array[j-1];
                    array[j-1] = array[j]-array[j-1];
                    array[j] = array[j]-array[j-1];
                }
            }
       }
   }
    /*
    void reOrderArray(vector<int> &array) {
        if (array.size()<=1) return;
        int pos=0;
        for(int i=0;i<array.size();i++){
            if(array[i]%2) {
                //“∆Œª
                if(i==pos){
                    pos++;
                    continue;
                }
                int j=i,tem = array[i];
                while(j>pos){
                     array[j] = array[j-1];
                     j--;
                }
                array[pos++] = tem;
            }
        }
        return;
    }*/
};

int main()
{
    Solution a;
    vector<int> s = {1,2,3,4,5,6,7,8};

    a.reOrderArray(s);
    for(int i=0;i<8;i++){
        cout<<s[i]<<" ";
    }
    return 0;
}
