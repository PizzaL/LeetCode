#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > matrixReshape(vector<vector<int> >& nums, int r, int c) {
        if (r*c != nums.size()*nums[0].size())
            return nums;
        vector<vector<int> > res;
        for (size_t i=0; i<r; ++i)
        {
            vector<int> row(c, 0);
            res.push_back(row);
        }
        for (size_t i=0; i<nums.size(); ++i)
        {
            for (size_t j=0; j<nums[i].size(); ++j)
            {
                int pos = i*nums[i].size() + j;
                res[pos/c][pos%c]=nums[i][j];
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