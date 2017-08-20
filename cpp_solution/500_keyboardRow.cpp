#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const string firstRow="qwertyuiop";
const string secondRow="asdfghjkl";
const string thirdRow="zxcvbnm";

class Solution {
public:
    int calWord(const string& word)
    {
        string lowerWord = word;
        std::transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);
        int value = 0;
        for (size_t i=0; i<lowerWord.size(); ++i)
        {
            char ch = lowerWord[i];
            if ( firstRow.find(ch) != string::npos )
                value = value | 1;
            if ( secondRow.find(ch) != string::npos )
                value = value | 2;
            if ( thirdRow.find(ch) != string::npos )
                value = value | 4;
        }
        return value;
    }

    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        for (size_t i=0; i<words.size(); ++i)
        {
            int value = calWord(words[i]);
            if ( value == 1
              || value == 2
              || value == 4 )
                res.push_back(words[i]);
        }
        return res;
    }
};

int main()
{
	Solution solution;
	vector<string> words;
	words.push_back("Hello");
	words.push_back("Alaska");
	words.push_back("Dad");
	words.push_back("Peace");
	vector<string> res = solution.findWords(words);
	cout << res.size() << endl;
	return 0;
}