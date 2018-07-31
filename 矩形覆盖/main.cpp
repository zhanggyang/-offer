#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int rectCover(int number) {
        if(number<=0) return 0;
        if(number<=2) return number;
        int a = 1;//Êú×ÅÌî³ä
        int b = 2;//ºá×ÅÌî³ä
        while(number>2){
            b = a+b;
            a = b-a;
            number--;
        }
        return b;

    }
};

int main()
{
    Solution a;
    for(int i=0;i<5;i++) cout << a.rectCover(i) << endl;
    return 0;
}
