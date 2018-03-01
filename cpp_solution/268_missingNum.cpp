#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size()*(nums.size()+1)/2;
        for (auto& num:nums)
            res-=num;
        return res;
    }
};

int main()
{
	Solution solution;
	return 0;
}
