#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    int findMinRadius(vector<int>& houses, int lastHeaterIdx, int curr)
    {
        int res = 0;
        for (size_t i=lastHeaterIdx+1; i<curr; ++i)
        {
            int dis = min(houses[i]-houses[lastHeaterIdx], houses[curr]-houses[i]);
            res = max(dis, res);
        }
        return res;
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int idx = 0;
        int res = 0;
        int lastHeater = 0;
        for (size_t i=0; i<houses.size(); ++i)
        {
            if (houses[i] >= heaters[idx])
            {
                if (lastHeater == 0)
                {   // first heater
                    res = houses[i]-houses[0];
                } else 
                {
                    res = max(res, findMinRadius(houses, lastHeaterIdx, i));
                }
                ++idx;
                lastHeaterIdx = i;
            }
        }
        if (lastHeaterIdx!=houses.size()-1)
        {
            res = max(res, houses[houses.size()-1]-houses[lastHeaterIdx]);
        }
        return res;
    }
};

int main()
{
	Solution solution;
	return 0;
}