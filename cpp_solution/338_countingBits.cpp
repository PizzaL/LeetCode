#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        0 1 2 3 4 5 6 7 8 9 10
        0 1 1 2 1 2 2 3 1 
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