#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int sum = 0;
        for (auto &num:nums)
            sum+=num;
        int ave = sum/nums.size();
        if ( (ave+1)*nums.size()-sum < sum-ave*nums.size() )
            ++ave;
        int res = 0;
        for (auto &num:nums)
            res += abs(ave-num);
        return res;
    }
};
int main()
{
	Solution solution;
	return 0;
}