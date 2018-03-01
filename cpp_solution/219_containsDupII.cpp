#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size()<=k+1)
        {
            set<int> numSet(nums.begin(), nums.end());
            return nums.size()>1 && numSet.size() != nums.size();
        }
        else
        {
            set<int> numSet(nums.begin(), nums.begin()+k+1);
            for (size_t i=k+1; i<nums.size(); ++i)
            {
                if (numSet.size() < k+1)
                    return true;
                else
                {
                    numSet.erase(nums[i-k-1]);
                    numSet.insert(nums[i]);
                }
            }
            if (numSet.size() < k+1)
                return true;
            else
                return false;
        }
    }
};

int main()
{
	Solution solution;
	return 0;
}
