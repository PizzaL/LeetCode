#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        nums.insert(nums.begin(), nums.end()-k, nums.end());
        nums.erase(nums.end()-k, nums.end());
    }
};

int main()
{
	Solution solution;
	return 0;
}