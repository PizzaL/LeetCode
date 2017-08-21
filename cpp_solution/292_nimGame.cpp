#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        return n%4!=0;
    }
};

int main()
{
	Solution solution;
    cout << solution.canWinNim(5) << endl;
	return 0;
}