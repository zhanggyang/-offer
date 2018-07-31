#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jumpFloorII(int number) {
        if(number<=0) return -1;
        int num =1;

        while(--number) num *=2;

        return num;

    }
};

int main()
{
    Solution a;
    for(int i=0;i<5;i++){

        cout << a.jumpFloorII(i) << endl;
    }

    return 0;
}
