#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> map1;
        for (auto num:nums1)
        {
            if (map1.find(num)!=map1.end() )
                ++map1[num];
            else
                map1[num] = 1;
        }
        map<int, int> map2;
        for (auto num:nums2)
        {
            if (map2.find(num)!=map2.end())
                ++map2[num];
            else
                map2[num]=1;
        }
        vector<int> res;
        for (auto& item:map1)
        {
            if (map2.find(item.first)!=map2.end())
            {
                for (size_t i=0; i<min(item.second, map2[item.first]); ++i)
                    res.push_back(item.first);
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