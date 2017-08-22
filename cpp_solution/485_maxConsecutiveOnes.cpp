#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res=0;
        int curr = 0;
        for (size_t i=0; i<nums.size(); ++i)
        {
            if (nums[i] == 1)
                ++curr;
            else
            {
                if ( curr > res )
                    res = curr;
                curr = 0;
            }
        }
        if (curr > res)
            res = curr;
        return res;
    }
};

int main()
{
	Solution solution;
	return 0;
}