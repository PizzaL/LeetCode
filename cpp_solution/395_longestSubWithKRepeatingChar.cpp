#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    struct Match {
        map<char, int> chars;
        set<char> val;
    };

    bool update(Match& match, char ch, int k)
    {
        if (match.chars.find(ch)!=match.chars.end())
        {
            ++match.chars[ch];
            if (match.chars[ch]==k)
            {
                match.chars.erase(ch);
                match.val.insert(ch);
                return true;
            }
            return false;
        } else if (match.val.find(ch)!=match.val.end())
        {
            return true;
        } else
        {
            match.chars[ch] = 1;
            return false;
        }
    }

    int longestSubstring(const string& s, int k) {
        if (k<=1)
            return s.length();
        vector<int> res(s.length()+1, 0);
        Match match;
        int r = 0;
        for (size_t i=1; i<=s.length(); ++i)
        {
            if (update(match, s[i-1], k))
                res[i]=res[i-1]+1;
            else 
                res[i]=0;
            cout << i << " " << res[i] << endl;
            r = max(r, res[i-1]);
        }
        return r;
    }
};

int main()
{
	Solution solution;
    cout << solution.longestSubstring("aaabababc", 2);
	return 0;
}