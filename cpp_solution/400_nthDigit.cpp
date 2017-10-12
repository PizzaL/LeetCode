#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findNthDigit(int num, int& n)
    {
        vector<int> digits;
        while (num > 0)
        {
            digits.push_back(num%10);
            num /= 10;
        }
        if (n > digits.size())
        {
            n -= digits.size();
            return -1;
        }
        else
            return digits[digits.size() - n ];
    }

    int findNthDigit(int n) {
        int num = 1;
        while (n > 0)
        {
            int res = findNthDigit(num, n);
            if (res >= 0)
                return res;
            ++num;
        }
        return -1;
    }
};

int main()
{
	Solution solution;
    cout << solution.findNthDigit(11);
	return 0;
}