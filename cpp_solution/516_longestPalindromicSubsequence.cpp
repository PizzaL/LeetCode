#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int count[1000+5][1000+5];
        count[0][0]=0;
        for (size_t i=0; i<s.length();++i)
        {
            count[i][0]=0;
            count[i][1]=1;
        }
        for (size_t i=2; i<=s.length(); ++i)
        {
            for (size_t j=0; j<s.length()-i+1; ++j)
            {
                count[j][i]=max(count[j][i-1], count[j+1][i-1]);
                if (s[j]==s[j+i-1])
                    count[j][i]=max(count[j][i], count[j+1][i-2]+2);
            }
        }
        return count[0][s.length()];
    }
};

int main()
{
	Solution solution;
    cout << solution.longestPalindromeSubseq("cbbd");
	return 0;
}