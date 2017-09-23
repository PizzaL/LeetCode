#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> distinct;
        for (size_t i=0; i<nums.size(); ++i)
        {
            if ( distinct.find(nums[i]) != distinct.end() )
                return true;
            distinct.insert(nums[i]);
        }
        return false;
    }
};

int main()
{
	Solution solution;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(4);
	nums.push_back(9);
	cout << solution.containsDuplicate(nums) << endl;
	return 0;
}