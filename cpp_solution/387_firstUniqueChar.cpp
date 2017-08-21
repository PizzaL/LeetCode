#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int charF[26];
        for (size_t i=0; i<26; ++i)
        {
            charF[i] = 0;
        }
        for (size_t i=0; i<s.size(); ++i)
        {
            ++charF[s[i]-'a'];
        }
        for (size_t i=0; i<s.size(); ++i)
        {
            if (charF[s[i]-'a'] == 1)
                return i;
        }
        return -1;  // shouldn't reach here
    }
};

int main()
{
	Solution solution;
    cout << solution.firstUniqChar("leetcode");
	return 0;
}