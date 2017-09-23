#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while (n>0)
        {
            char c = 'A'-1+n%26;
            if (0==n%26)
            {
                c = 'Z';
                n = n/26-1;
            } else
                n = n/26;
            res=string(1, c)+res;
        }
        return res;
    }
};

int main()
{
	Solution solution;
    cout << solution.convertToTitle(26*26) << endl;
	return 0;
}