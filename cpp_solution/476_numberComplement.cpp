#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        unsigned int res = 2;
        while (res <= num)
        {
            res *= 2;
        }
        return res-1-num;
    }
};

int main()
{
	Solution solution;
	int res = solution.findComplement(2147483647);
	cout << res << endl;
	return 0;
}