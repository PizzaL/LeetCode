#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> f;
        for (size_t i=0; i<nums.size(); ++i)
        {
            if ( f.find(nums[i])!=f.end() )
                ++f[nums[i]];
            else
                f[nums[i]] = 1;
        }
        for (map<int, int>::iterator it=f.begin(); it != f.end(); ++it)
        { 
            if ( it->second > nums.size()/2 )
                return it->first;
        }
        return 0;   // shouldn't reach here.
    }
};

int main()
{
	Solution solution;

	return 0;
}