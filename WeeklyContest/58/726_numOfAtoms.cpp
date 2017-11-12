#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <sstream>

using namespace std;

class Solution {
public:
    void findAtoms(const string& formula, string& currWord, int& count, size_t& i)
    {
        currWord =string();
        currWord+=formula[i];
        ++i;
        while (i<formula.size() && formula[i]>='a' && formula[i]<='z')
        {
            currWord+=formula[i];
            ++i;
        }
        string num;
        while (i<formula.size() && isdigit(formula[i]) )
        {
            num += formula[i];
            ++i;
        }
        count = 1;
        if (!num.empty())
            count = stoi(num.c_str());
    }
    map<string, int> findAtomsInPare(string& formula, size_t& i)
    {
        ++i;    // skip (
        map<string, int> res;
        for ( ;formula[i]!=')'; )
        {
            if (formula[i]!='(')
            {
                string currWord;
                int count;
                findAtoms(formula, currWord, count, i);
                if (res.find(currWord) != res.end() )
                    res[currWord]+=count;
                else
                    res[currWord]=count;
            } 
            else
            {
                map<string, int> tempRes=findAtomsInPare(formula, i);
                for (auto& record:tempRes)
                {
                    if (res.find(record.first)!=res.end())
                        res[record.first]+=record.second;
                    else
                        res[record.first] = record.second;
                }
            }
        }
        ++i; // skip )
        string num;
        while (i<formula.size() && isdigit(formula[i]) )
        {
            num += formula[i];
            ++i;
        }
        int count = 1;
        if (!num.empty())
            count = stoi(num.c_str());
        for (auto& record:res)
            record.second*=count;
        return res;
    }

    string countOfAtoms(string formula) {
        map<string, int> res;
        for (size_t i=0; i<formula.size();)
        {
            if (formula[i]!='(')
            {
                string currWord;
                int count;
                findAtoms(formula, currWord, count, i);
                if (res.find(currWord) != res.end() )
                    res[currWord]+=count;
                else
                    res[currWord]=count;
            } 
            else
            {
                map<string, int> tempRes=findAtomsInPare(formula, i);
                for (auto& record:tempRes)
                {
                    if (res.find(record.first)!=res.end())
                        res[record.first]+=record.second;
                    else
                        res[record.first] = record.second;
                }
            }
        }
        string resStr;
        for (auto& record:res)
        {
            resStr+=record.first;
            if (record.second!=1)
                resStr+=to_string(record.second);
        }
        return resStr;
    }
};

int main()
{
    Solution solution;
    return 0;
}