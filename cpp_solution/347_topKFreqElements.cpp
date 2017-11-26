#include <iostream>
#include <vector>
#include <algorithm>
#include <map> 

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> numFreq;
        for (auto num:nums)
            if (numFreq.find(num)==numFreq.end())
                numFreq[num] = 1;
            else
                ++numFreq[num];
        map<int, vector<int> > freqSorted;
        for (auto element:numFreq)
            if (freqSorted.find(element.second)==freqSorted.end())
                freqSorted[element.second]=vector<int>(1, element.first);
            else
                freqSorted[element.second].push_back(element.first);
        int count = 0;
        vector<int> res;
        for (auto it=freqSorted.rbegin(); it!=freqSorted.rend(); ++it)
        {
            if (count < k)
            {

                res.insert(res.end(), it->second.begin(), it->second.end());
                count+=it->second.size();
            }
            else
                break;
        }
        return res;
    }
};

int main()
{
	Solution solution;
	return 0;
}