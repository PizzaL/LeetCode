#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        vector<int> outliers;
        for (size_t i=0; i<nums.size()-1; ++i)
        {
            if (nums[i]>nums[i+1])
            {
                if (i==0 || nums[i+1]>=nums[i-1])
                    outliers.push_back(nums[i]);
                else 
                {
                    outliers.push_back(nums[i+1]);
                    nums[i+1]=nums[i];
                }
            }
        }
        return outliers.size()<=1;
    }
};

int main()
{
	Solution solution;
	return 0;
}