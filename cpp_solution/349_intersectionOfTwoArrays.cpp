#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> numSet1(nums1.begin(), nums1.end());
        set<int> numSet2(nums2.begin(), nums2.end());
        vector<int> res;
        for (set<int>::iterator it=numSet1.begin(); it!=numSet1.end(); ++it)
        {
            if ( numSet2.find(*it) != numSet2.end() )
            {
                res.push_back(*it);
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