#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool hasBits(int n, int digit)
    {
        if (n<2)
            return n != digit;
        if (n%2 == digit)
            return false;
        else 
            return hasBits(n/2, n%2);
    }
    bool hasAlternatingBits(int n) {
        if (n<=2)
            return true;
        else
            return hasBits(n/2, n%2);
    }
};

int main()
{
	Solution solution;
    cout << solution.hasAlternatingBits(11);
	return 0;
}