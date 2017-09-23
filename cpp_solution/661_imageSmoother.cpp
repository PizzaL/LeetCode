#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int min(const int a, const int b)
    {
        return a < b?a:b;
    }
    int smooth(const vector<vector<int> >& M, int r, int c)
    {
        int res = 0;
        int count = 0;
        for (size_t i=max(0, r-1); i<=min(M.size()-1, r+1); ++i)
            for (size_t j=max(0, c-1); j<=min(M[r].size()-1, c+1); ++j)
            {
                res +=M[i][j];
                ++count;
            }
        return res/count;
    }

    vector<vector<int> > imageSmoother(vector<vector<int> >& M) {
        vector<vector<int> > res;
        for (size_t i=0; i<M.size(); ++i)
        {
            vector<int> currRow = vector<int>();
            for (size_t j=0; j<M[i].size(); ++j)
            {
                currRow.push_back(smooth(M, i, j));
            }
            res.push_back(currRow);
        }
        return res;
    }
};
int main()
{
	Solution solution;
	return 0;
}