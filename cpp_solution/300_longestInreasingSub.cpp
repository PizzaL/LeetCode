#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void updateTail(vector<int>& tail, int start, int end, vector<int>& nums, int i)
    {
        if (start == end) {
            if ( end == tail.size() )
                tail.push_back(nums[i]);
            else 
                tail[start] = nums[i];
        }
        else {
            int curr = (start+end)/2;
            if (nums[i]>tail[curr])
                updateTail(tail, curr+1, end, nums, i);
            else 
                updateTail(tail, start, curr, nums, i);
        }
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> tail;
        int r = 0;
        for (size_t i=0; i<nums.size(); ++i)
        {
            updateTail(tail, 0, tail.size(), nums, i);
        }
        return tail.size();
    }
};

int main()
{
	Solution solution;
	return 0;
}