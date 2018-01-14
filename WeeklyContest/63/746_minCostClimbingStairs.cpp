#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <sstream>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> res(cost.size(), 0);
        res[0] = cost[0];
        res[1] = cost[1];
        for (size_t i=2; i<res.size(); ++i)
        {
            res[i]=min(res[i-2], res[i-1])+cost[i];
        }
        return min(res[cost.size()-1], res[cost.size()-2]);
    }
};

int main()
{
    Solution solution;
    return 0;
}