#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> count;
        for (auto ch:s)
        {
            if (count.find(ch)!=count.end())
                ++count[ch];
            else
                count[ch]=1;
        }
        map<int, string> res;
        for (auto ch:count)
        {
            if (res.find(ch.second)!=res.end())
                res[ch.second]+=ch.first;
            else
                res[ch.second]=string(1, ch.first);
        }
        string resStr;
        for (auto& r:res)
        {
            for (auto ch:r.second)
            {
                string curr(r.first, ch);
                resStr=curr+resStr;
            }
        }
        return resStr;
    }
};

int main()
{
	Solution solution;
    cout << solution.frequencySort("Aabb");
	return 0;
}