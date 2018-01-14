#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <sstream>

using namespace std;

bool compare(const string& s1, const string& s2)
{
    return s1.size() < s2.size();
}

map<char, int> generateLicense(const string& licensePlate)
{
    istringstream sin(licensePlate);
    char ch;
    map<char, int> res;
    while (sin >> ch)
    {
        if (isalpha(ch))
        {
            char key = tolower(ch);
            if (res.find(key)!=res.end())
            {
                ++res[key];
            }
            else
            {
                res[key]=1;
            }
        }
    }
    return res;
}

bool match(map<char, int>& license, const string& word)
{
    map<char, int> wordLicense = generateLicense(word);
    for(auto& item:license)
    {
        if ( wordLicense.find(item.first)==wordLicense.end() 
          || wordLicense[item.first]<item.second )
            return false;
    }
    return true;
}

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        map<char, int> license = generateLicense(licensePlate);
        stable_sort(words.begin(), words.end(), compare);
        for (auto& word:words)
        {
            if (match(license, word))
                return word;
        }
        return string();    // shouldn't reach here
    }
};

int main()
{
    Solution solution;
    return 0;
}