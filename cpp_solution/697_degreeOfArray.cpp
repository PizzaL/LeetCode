#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Num {
    int startIdx, endIdx, count;
    Num()
        :startIdx(0), endIdx(0), count(0)
    {}
    Num(int startIdx, int endIdx, int count)
        : startIdx(startIdx), endIdx(endIdx), count(count)
    {}
};

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, Num> frequency;
        for (size_t i=0; i<nums.size(); ++i)
        {
            if (frequency.find(nums[i]) == frequency.end())
            {
                frequency[nums[i]] = Num(i, i, 1);
            } else
            {
                ++frequency[nums[i]].count;
                frequency[nums[i]].endIdx = i;
            }
        }
        int count = 0, res = 0;
        for (auto &item : frequency)
        {
            if ( item.second.count > count 
              || (item.second.count == count && item.second.endIdx-item.second.startIdx+1 < res) )
            {
                count = item.second.count;
                res = item.second.endIdx - item.second.startIdx + 1;
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