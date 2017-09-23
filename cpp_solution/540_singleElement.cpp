#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findSingle(vector<int>& nums, int start, int end)
    {
        if (start == end)
        {
            return nums[start];
        }
        int mid = (start+end)/2;
        if (nums[mid-1]!= nums[mid] && nums[mid]!=nums[mid+1])
            return nums[mid];
        else if (nums[mid-1] == nums[mid])
        {
            if ( (mid-start)%2==0 )
                return findSingle(nums,start, mid);
            else
                return findSingle(nums, mid+1, end);
        }
        else
        {
            if ( (mid-start)%2==0 )
                return findSingle(nums, mid, end);
            else
                return findSingle(nums, start, mid-1);
        }
    }
    int singleNonDuplicate(vector<int>& nums) {
        return findSingle(nums, 0, nums.size()-1);
    }
};

int main()
{

	return 0;
}