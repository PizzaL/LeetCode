#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (size_t i=0; i<nums.size(); ++i)
        {
            res = res^nums[i];
        }
        return res;
    }
};

int main()
{
    Solution solution;
	return 0;
}