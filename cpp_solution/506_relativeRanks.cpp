#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const string goldStr="Gold Medal";
const string silverStr="Silver Medal";
const string bronzeStr="Bronze Medal";

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> res;
        if (nums.size() < 3)
        {
            if (nums.size() == 0)
                return res;
            else if (nums.size() == 1)
            {
                res.push_back(goldStr);
                return res;
            } else if (nums.size() == 2)
            {
                int gold = max(nums[0], nums[1]);
                if (nums[0] == gold)
                    res.push_back(goldStr);
                else
                    res.push_back(silverStr);
                if (nums[1] == gold)
                    res.push_back(goldStr);
                else
                    res.push_back(silverStr);
                return res;
            }
        }

        vector<int> rank(nums.begin(), nums.end() );
        sort(rank.begin(), rank.end());
        map<int, string> rankMap;
        for (size_t i=0; i<rank.size(); ++i)
        {
            rankMap[rank[i]]=to_string(rank.size()-i);
        }
        rankMap[rank[rank.size()-1] ]= goldStr;
        rankMap[rank[rank.size()-2] ]= silverStr;
        rankMap[rank[rank.size()-3] ]= bronzeStr;
        for (size_t i=0; i<nums.size(); ++i)
            res.push_back(rankMap[nums[i]]);
        return res;
    }
};

int main()
{
	Solution solution;
    vector<int> nums;
    vector<string> res = solution.findRelativeRanks(nums);
	cout << res[0] << ", " << res[1] << endl;
	return 0;
}