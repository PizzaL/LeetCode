#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (size_t i=0; i<nums.size(); ++i)
        {
        	vector<int>::iterator pos = find(nums.begin(), nums.end(), target-nums[i]);
        	if ( pos != nums.end() && pos - nums.begin() != i)
        	{
        		vector<int> res;
        		res.push_back(i);
        		res.push_back(pos-nums.begin());
        		return res;
        	}
        }
    	vector<int> res;
   		return res;
   	}
};	

int main()
{
	Solution solution;
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(11);
	nums.push_back(15);
	int target = 9;
	vector<int> res = solution.twoSum(nums, target);
	cout << res[0] << ", " << res[1] << endl;
	return 0;
}