#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        if (nums.size() == 1)
            return to_string(nums[0]);
        else if (nums.size() == 2)
            return to_string(nums[0]) +"/"+to_string(nums[1]);
        string res;
        res = to_string(nums[0])+"/(";
        for (size_t i=1; i<nums.size()-1; ++i)
        {
            res+=to_string(nums[i])+"/";
        }
        res+=to_string(nums[nums.size()-1])+")";
        return res;
    }
};

int main()
{
	Solution solution;
	return 0;
}