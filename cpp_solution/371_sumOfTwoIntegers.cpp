#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        if (b == 0)
        	return a;
        else
        	return getSum(a^b, (a&b)<<1);
    }
};

int main()
{
	Solution solution;
	cout << solution.getSum(10, 3);
	return 0;
}