#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int curr=0, s=0;
        while (s<nums.size() )
        {
            if (nums[s]!=0)
            {
                if (s!=curr)
                {
                    nums[curr]=nums[s];
                }
                ++curr; ++s;
            } else
            ++s;
        }
        for (size_t i=curr; i<nums.size(); ++i)
            nums[i]=0;
    }
};

int main()
{
	Solution solution;
	return 0;
}