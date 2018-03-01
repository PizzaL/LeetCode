#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    bool intersect(const vector<pair<int, int> >& points, const int lastIdx, const int idx)
    {
        return points[lastIdx].second>=points[idx].first && points[lastIdx].second<=points[idx].second;
    }

    int findMinArrowShots(vector<pair<int, int> >& points) {
        for (auto& item:points)
        {
            int temp = item.first;
            item.first = item.second;
            item.second = temp;
        }
        sort(points.begin(), points.end());
        for (auto& item:points)
        {
            int temp = item.first;
            item.first = item.second;
            item.second = temp;
        }
        int idx = 0;
        int lastIdx = 0;
        int res = 0;
        while (idx<points.size())
        {
            ++res;
            while ( idx<points.size() && intersect(points, lastIdx, idx) )
                ++idx;
            if ( idx<points.size() )
            {
                lastIdx=idx; 
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
