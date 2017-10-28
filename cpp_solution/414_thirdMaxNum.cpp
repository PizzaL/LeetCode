#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void insertTop3(vector<int>& res, int num)
    {
        
    }

    int getThird(vector<int>& nums)
    {
        if (nums.size() < 3)
            return nums[nums.size()-1];
        else
            return nums[3];
    }

    int thirdMax(vector<int>& nums) {
        vector<int> res;
        for (size_t i=0; i<nums.size(); ++i)
        {
            insertTop3(res, nums[i]);
        }
        return getThird(res);
    }
};

int main()
{
	Solution solution;
	return 0;
}