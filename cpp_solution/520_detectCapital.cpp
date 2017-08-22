#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word[0]>='a')
        {
            for (size_t i=1; i<word.size(); ++i)
            {
                if (word[i]<'a')
                    return false;
            }
            return true;
        } 
        else
        {
            bool lower = false, upper = false;
            for (size_t i=1; i<word.size(); ++i)
            {
                if (word[i]<'a')
                    upper=true;
                else
                    lower=true;
            }
            return !(lower && upper);
        }
    }
};

int main()
{
	Solution solution;
	return 0;
}