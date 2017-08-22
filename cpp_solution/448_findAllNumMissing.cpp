#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res(nums.size()+1, 0);
        for (size_t i=0;i<nums.size(); ++i)
        {
            ++res[nums[i]];
        }
        nums.clear();
        for (size_t i=1; i<res.size(); ++i)
        {
            if (res[i] == 0)
            {
                nums.push_back(i);
            }
        }
        return nums;
    }
};

int main()
{
	Solution solution;
	return 0;
}