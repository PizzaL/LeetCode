#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int res = 0;
        for (size_t i=0; i<flowerbed.size(); ++i)
        {
            if ( flowerbed[i]==0
              && (i==0 || flowerbed[i-1] == 0)
              && (i+1==flowerbed.size() || flowerbed[i+1] == 0) )
            {
                flowerbed[i] = 1;
                ++res;
                ++i;
            }
        }
        return res >= n;
    }
};

int main()
{
	Solution solution;
	return 0;
}