#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res;
        set<int> appear;
        int sum = 0;
        for (auto num:nums)
        {
            sum+=num;
            if (appear.find(num)!=appear.end() )
            {
                res.push_back(num);
            }
            else
                appear.insert(num);
        }
        res.push_back( (1+nums.size())*nums.size()/2-sum+res[0] );
        return res;
    }
};

int main()
{
	Solution solution;
	return 0;
}