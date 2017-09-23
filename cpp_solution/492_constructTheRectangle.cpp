#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> res;
        int start = sqrt(area);
        for (size_t i=start; i<=area; ++i)
        {
            if ( area%i == 0 && i>=area/i )
            {
                res.push_back(i);
                res.push_back(area/i);
                return res;
            }
        }
        return res; // shouldn't reach here
    }
};

int main()
{
	Solution solution;
	return 0;
}