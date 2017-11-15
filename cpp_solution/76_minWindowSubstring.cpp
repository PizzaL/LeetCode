#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <sstream>

using namespace std;

class Solution {
public:
    string find(string S, int pos, string T)
    {
        cout << "pos=" << pos << endl;
        string res;
        int startT = 0;
        for (size_t i=pos; i<S.length();)
        {
            while (startT < T.length() && i<S.length() && S[i]==T[startT])
            {
                res += S[i];
                ++i;
                ++startT;
            }
            if ( startT == T.length() )
            {
                return res;
            }
            while (i<S.length() && S[i]!=T[startT])
            {
                res += S[i];
                ++i;
            }
        }
        if ( startT == T.length() )
        {
            return res;
        }
        else
            return string();
    }

    string minWindow(string S, string T) {
        string res=S+"a";
        for (size_t i=0; i<S.length();)
        {
            while (i<S.length() && S[i]!=T[0])
                ++i;
            string currRes = find(S, i, T);
            cout << "currRes=" << currRes << endl;
            if (currRes.length()!=0 && currRes.length() < res.length())
                res = currRes;
            ++i;
        }
        if (res.length() > S.length())
            return string();
        else
            return res;
    }
};

int main()
{
    Solution solution;
    cout << solution.minWindow("abcdebdde","bdge");
    return 0;
}