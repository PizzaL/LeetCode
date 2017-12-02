#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {

        vector<vector<bool> > match;
        for (size_t i=0; i<=s.length(); ++i)
            match.push_back( vector<bool>(p.length()+1, false) );
        match[0][0]=true;
        for (size_t i=1; i<=s.length(); ++i)
        {
            if (s[i-1]=='*')
                match[i][0]=match[i][0] || match[i-1][0];
        }
        for (size_t j=1; j<=p.length(); ++j)
        {
            if (p[j-1]=='*')
                match[0][j]=match[0][j] || match[0][j-1];
        }
        for (size_t i=1; i<=s.length(); ++i)
        {
            for (size_t j=1; j<=p.length(); ++j)
            {
                if (s[i-1]=='*')
                {
                    match[i][j]=match[i][j] || match[i-1][j-1] || match[i][j-1] || match[i-1][j];
                } 
                if (p[j-1]=='*')
                {
                    match[i][j]=match[i][j] || match[i-1][j-1] || match[i-1][j] || match[i][j-1];
                }
                if (s[i-1]=='?' || p[j-1]=='?' || s[i-1]==p[j-1])
                {
                    match[i][j]=match[i][j] || match[i-1][j-1];
                }
            }
        }
        return match[s.length()][p.length()];
    }
};

int main()
{
	Solution solution;
    cout << solution.isMatch("a", "*a*") << endl;
	return 0;
}