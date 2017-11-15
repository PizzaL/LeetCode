#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool repeat(string& pattern, string& s)
    {
        if ( pattern.length() == s.length() 
          || s.length() % pattern.length() != 0 )
        {
            return false;
        }
        int pos = 0;
        while (s.find(pattern, pos) == pos)
            pos+=pattern.length();
        return pos == s.length();
    }

    bool repeatedSubstringPattern(string s) {
        string pattern;
        for (size_t i=0; i<s.length(); ++i)
        {
            pattern += s[i];
            if (repeat(pattern, s))
                return true;
        }
        return false;
    }
};

int main()
{
	Solution solution;
    cout << solution.repeatedSubstringPattern("abababa");
	return 0;
}