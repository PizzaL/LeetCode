#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = 0;
        for (auto &num : nums)
        {
            diff ^= num;
        }
        int flag = diff & -diff;
        vector<int> res = {0, 0};
        for (auto &num : nums)
        {
            if (num&flag)
            {
                res[0] = res[0]^num;
            } else
            {
                res[1] = res[1]^num;
            }
        }
        return res;
    }
};

int main()
{
	Solution solution;
	return 0;
}