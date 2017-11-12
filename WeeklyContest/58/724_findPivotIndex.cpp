#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <sstream>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum = 0;
        int rightSum = 0;
        for (auto num:nums)
            rightSum+=num;
        for(size_t i=0; i<nums.size(); ++i)
        {
            if (i>0)
                leftSum+=nums[i-1];
            rightSum-=nums[i];
            if (leftSum == rightSum)
                return i;
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1,7,3,6,5,6};
    cout << solution.pivotIndex(nums);
    return 0;
}