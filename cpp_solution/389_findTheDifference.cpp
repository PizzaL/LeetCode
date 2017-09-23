#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int ch[26];
        for (size_t i=0;i<26; ++i)
        {
            ch[i]=0;
        }
        for (size_t i=0; i<t.size(); ++i)
        {
            ++ch[t[i]-'a'];
        }
        for (size_t i=0; i<s.size(); ++i)
        {
            --ch[s[i]-'a'];
        }
        for (size_t i=0; i<26; ++i)
        {
            if (ch[i] == 1)
                return 'a'+i;
        }
        return 'a'; // shouldn't reach here
    }
};

int main()
{
	Solution solution;
	return 0;
}