#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0;
        if (s.empty())
            return res;
        int count = 0;
        int count1 = 0;
        for (size_t i=0; i<s.length();)
        {
            char curr = s[i];
            count = 0;
            while (i<s.length() && s[i] == curr)
            {
                ++i;
                ++count;
            }
            res += min(count, count1);
            count1 = 0;
            while (i<s.length() && s[i] != curr)
            {
                ++i;
                ++count1;
            }
            res += min(count, count1);
        }
        return res;
    }
};

int main()
{
	Solution solution;
    cout << solution.countBinarySubstrings("001100");
	return 0;
}