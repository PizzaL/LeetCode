#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <sstream>

using namespace std;

class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int res = 0;
        for (size_t row_s=0; row_s<grid.size()-1; ++row_s)
        {
            for (size_t col_s=0; col_s<grid[0].size()-1; ++col_s)
            {
                if (grid[row_s][col_s]!=1)
                {
                    continue;
                }
                for (size_t row_e=row_s+1; row_e<grid.size(); ++row_e)
                {
                    if (grid[row_e][col_s]!=1)
                        continue;
                    for (size_t col_e=col_s+1; col_e<grid[0].size(); ++col_e)
                    {
                        if (grid[row_s][col_e]!=1)
                            continue;
                        if (grid[row_e][col_e]==1)
                            ++res;
                    }
                }
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