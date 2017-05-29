#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int res = 0;
        set<int> totalSet(nums.begin(), nums.end());
        for (size_t i=0; i<nums.size(); ++i)
        {
            if ( totalSet.find(i) == totalSet.end() )
                continue;
            set<int> numSet(nums.begin(), nums.end());
            int currRes = 0;
            int currPos = i;
            while ( numSet.find(currPos) != numSet.end() )
            {
                numSet.erase(currPos);
                totalSet.erase(currPos);
                currPos = nums[currPos];
                ++currRes;
            }
            if (currRes > res)
                res = currRes;
        }
        return res;
    }
};

int main()
{
    vector<int> nums;
	Solution solution;
	solution.arrayNesting(nums);
	return 0;
}