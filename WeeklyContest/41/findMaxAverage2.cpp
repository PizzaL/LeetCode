#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res = 0;
        for (size_t i=0; i<k; ++i )
            res += nums[i];
        int previousSum = res;
        int start = 0, end = k;
        for (size_t i=k; i<nums.size(); ++i)
        {
            previousSum += nums[i] - nums[i-k];
            if ( previousSum > res)
            {
                res = previousSum;
                start = i;
                end = i+k;
            }
        }
        res = 
        return finalRes;
    }
};
int main()
{
	vector<vector<int> > ops;
    vector<int> op1;
    op1.push_back(2);
    op1.push_back(2);
    ops.push_back(op1);
    vector<int> op2;
    op2.push_back(3);
    op2.push_back(3);
    ops.push_back(op2);

	Solution solution;
	cout << solution.maxCount(3, 3, ops) << endl;
	return 0;
}