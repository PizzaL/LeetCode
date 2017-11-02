#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res = 0;
        vector<int> count(nums.size(), 0);
        for (size_t i=0; i<nums.size(); ++i)
        {
            if (i==0)
            {
                count[0]=1;
                res = 1;
            }
            else if (nums[i]>nums[i-1])
            {
                count[i]=count[i-1]+1;
                if (count[i]>res)
                    res = count[i];
            } else
            {
                count[i]=1;
            }
        }
        return res;
    }
};

int main()
{
	Solution solution;
    vector<int> nums={1,2,3,2,1};
    solution.findLengthOfLCIS(nums);
	return 0;
}