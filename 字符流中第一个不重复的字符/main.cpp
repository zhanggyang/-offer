#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string s;
    int hash[256] = {0};
    //vector<int> hash(256);
  //Insert one char from stringstream
    void Insert(char ch)
    {
        s.push_back(ch);
        ++hash[ch];
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        for(auto c : s){
            if(hash[c]== 1) return c;
        }
        return '#';
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
