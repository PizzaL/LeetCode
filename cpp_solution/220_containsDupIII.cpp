#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size()<2 || k==0)
            return false;
        set<int> numSet( nums.begin(), nums.begin()+min((int)nums.size(), k+1) );
        for (size_t i=k+1; i<nums.size(); ++i)
        {
            if (*numSet.rbegin()-*(numSet.begin())<=t)
                return true;
            else
            {
                numSet.erase(nums[i-k-1]);
                numSet.insert(nums[i]);
            }
        }
        return *numSet.rbegin()-*(numSet.begin())<=t;

    }
};

int main()
{
	Solution solution;
	return 0;
}
