#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int res = 0; 
        int rightHeater = 0;
        for (size_t i = 0; i<houses.size(); ++i)  
        {
            while (rightHeater<heaters.size() && heaters[rightHeater] <= houses[i])
                ++rightHeater;
            if (rightHeater == 0)
            {
                res = max(res, heaters[rightHeater]-houses[i]);
            } else if (rightHeater == heaters.size() )
            {
                res = max(res, houses[i]-heaters[rightHeater-1]);
            }
            else
            {
                int dist = min(heaters[rightHeater]-houses[i], houses[i]-heaters[rightHeater-1]);
                res = max(res, dist);
            }
        } 
        return res;
    }
};

int main()
{
	Solution solution;
    vector<int> houses;
    houses.push_back(1);
    houses.push_back(2);
    houses.push_back(3);
    vector<int> heaters;
    heaters.push_back(1);
    cout << solution.findRadius(houses, heaters);
	return 0;
}