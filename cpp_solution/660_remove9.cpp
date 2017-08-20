#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int newInteger(int n) {
        if (n >= 9)
            return n%9+10*newInteger(n/9);
        else
            return n;
    }
};

int main()
{
	Solution solution;
	int res = solution.newInteger(9);
	cout << res << endl;
	return 0;
}