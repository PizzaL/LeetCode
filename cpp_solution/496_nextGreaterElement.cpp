#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> res;
        for (size_t i=0; i<findNums.size(); ++i)
        {
            int greater = -1;
            for ( vector<int>::iterator it = find(nums.begin(), nums.end(), findNums[i]); 
                  it != nums.end(); 
                  ++it)
            {
                if ( *it >findNums[i] )
                {
                    greater = *it;
                    break;
                }
            }
            res.push_back(greater);
        }
        return res;
    }
};

int main()
{
	Solution solution;
	return 0;
}