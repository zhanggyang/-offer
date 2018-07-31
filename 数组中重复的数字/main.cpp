#include <iostream>

using namespace std;
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        int tag[length];
        for(int i=0;i<length;i++){
            tag[i] = 0;
        }
        for(int i=0;i<length;i++){
            if(tag[numbers[i]]==1) {
               *duplication = numbers[i];
               return true;
            }
            else tag[numbers[i]] = 1;
        }

        return false;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
