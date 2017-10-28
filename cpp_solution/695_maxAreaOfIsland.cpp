#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findIsland(vector<vector<int> >& grid, bool map[][50], int i, int j)
    {
        if (map[i][j] == false)
            return 0;
        int res = 1;
        map[i][j]=false;
        if (i-1>=0 && map[i-1][j] && grid[i-1][j])
            res += findIsland(grid, map, i-1, j);
        if (j+1 < grid[i].size() && map[i][j+1] && grid[i][j+1])
            res += findIsland(grid, map, i, j+1);
        if (i+1< grid.size() && map[i+1][j] && grid[i+1][j])
            res += findIsland(grid, map, i+1, j);
        if (j-1>=0 && map[i][j-1] && grid[i][j-1])
            res += findIsland(grid, map, i, j-1);
        return res;
    }

    int maxAreaOfIsland(vector<vector<int> >& grid) {
        bool map[50][50];
        for (size_t i=0; i<50; ++i)
            for (size_t j=0; j<50; ++j)
                map[i][j]=true;
        int res = 0;
        for (size_t i=0; i<grid.size(); ++i)
            for (size_t j=0; j<grid[i].size(); ++j)
                if (map[i][j] && grid[i][j])
                    res = max(res, findIsland(grid, map, i, j));
        return res;
    }
};

int main()
{
	Solution solution;
	return 0;
}