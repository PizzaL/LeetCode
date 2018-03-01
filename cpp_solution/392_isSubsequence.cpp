#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx = 0;
        for (const auto& item:s)
        {
            while (idx<t.length() && t[idx]!=item)
                ++idx;
            if (idx>=t.length())
                return false;
            else
                ++idx;
        }
        return true;
    }
};

int main()
{
	Solution solution;
    cout << solution.isSubsequence("abc", "adfinefbkajlksdjflib");
	return 0;
}
