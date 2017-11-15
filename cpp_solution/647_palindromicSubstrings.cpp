#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int find(string& s, int pos)
    {
        int res = 0;
        int i = 0; 
        while (pos>=i && pos+i < s.length() && s[pos+i]==s[pos-i])
        {
            ++i;
            ++res;
        }
        i = 0;
        while (pos>=i && pos+i+1<s.length() && s[pos-i]==s[pos+i+1])
        {
            ++i;
            ++res;
        }
        return res;
    }

    int countSubstrings(string s) {
        int res = 0;
        for (size_t i=0; i<s.length(); ++i)
        {
            res += find(s, i);
        }
        return res;
    }
};

int main()
{
	Solution solution;
    cout << solution.countSubstrings("abc");
	return 0;
}