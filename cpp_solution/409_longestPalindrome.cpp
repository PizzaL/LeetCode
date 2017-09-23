#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> count;
        for (size_t i=0; i<s.size(); ++i)
        {
            if (count.find(s[i])!=count.end())
                ++count[s[i]];
            else
                count[s[i]]=1;
        }
        int res=0;
        bool single = true;
        for (map<char, int>::iterator it=count.begin(); it!=count.end(); ++it)
        {
            if (it->second%2 == 0)
                res += it->second;
            else if (single)
            {
                res += it->second;
                single = false;
            } else
            {
                res += it->second-1;
            }
        }
        return res;
    }
};

int main()
{
	Solution solution;
	return 0;
}