#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }    
        int smallest = nums[0];
        int sum = 0;
        for (size_t i=0; i<nums.size(); ++i)
        {
            sum+=nums[i];
            if (nums[i]<smallest)
                smallest = nums[i];
        }
        return (sum-nums.size()*smallest);
    }
};

int main()
{
	Solution solution;
	return 0;
}