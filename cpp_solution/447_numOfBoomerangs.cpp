#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int calDist(pair<int, int>& p1, pair<int, int>& p2)
    {
        return (p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second);
    }

    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        map<int, int> dists;
        int res = 0;
        for (auto& p1:points)
        {
            dists.clear();
            for (auto& p2:points)
            {
                if (p1 == p2)
                    continue ;
                int dist = calDist(p1, p2);
                if (dists.find(dist)!=dists.end())
                {
                    ++dists[dist];
                } else
                {
                    dists[dist]=1;
                }
            }
            for (auto& dist:dists)
            {
                res += dist.second*(dist.second-1);
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