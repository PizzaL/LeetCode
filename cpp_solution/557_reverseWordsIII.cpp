#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        istringstream sin(s);
        string word;
        sin >> word;
        string res( word.rbegin(), word.rend() );
        while (sin >> word)
        {
            string reverseWord(word.rbegin(), word.rend());
            res += " ";
            res += reverseWord;
        }
        return res;
    }
};

int main()
{
	Solution solution;
	string res = solution.reverseWords("Let's take LeetCode contest");
	cout << res << endl;
	return 0;
}