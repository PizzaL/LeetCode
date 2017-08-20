#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        set<int> res(candies.begin(), candies.end());
        return min(res.size(), candies.size()/2);
    }
};

int main()
{
	Solution solution;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	int res = solution.distributeCandies(nums);
	cout << res << endl;
	return 0;
}