#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <sstream>

using namespace std;

class Solution {
public:

    bool similar(string& word1, string& word2, map<string, vector<string> >& dict)
    {
        if ( dict.find(word1) != dict.end() )
        {
            vector<string>& words = dict[word1];
            return find(words.begin(), words.end(), word2)!=words.end();
        }
        return false;
    }

    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string> > pairs) {
        map<string, vector<string> > dict;
        for (auto item:pairs)
        {
            if (dict.find(item.first)!=dict.end())
                dict[item.first].push_back(item.second);
            else
                dict[item.first] = vector<string>(1, item.second);
            if (dict.find(item.second)!=dict.end())
                dict[item.second].push_back(item.first);
            else
                dict[item.second] = vector<string>(1, item.first);
        }
        if (words1.size() != words2.size())
            return false;
        for (size_t i=0; i<words1.size(); ++i)
        {
            if ( words1[i]!=words2[i] 
              && !similar(words1[i], words2[i], dict) 
              && !similar(words2[i], words1[i], dict) )
                return false;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    return 0;
}