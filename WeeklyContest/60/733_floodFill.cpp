#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <sstream>

using namespace std;

class Solution {
public:
    void floodFill(vector<vector<int> >& image, int sr, int sc, int oldColor, int newColor, vector<vector<bool> >& visited)
    {
        if (sr >=0 && sr < image.size() && sc >=0 && sc < image[0].size())
        {
            if (!visited[sr][sc] && image[sr][sc]==oldColor)
            {
                visited[sr][sc]=true;
                image[sr][sc]=newColor;
                floodFill(image, sr-1, sc, oldColor, newColor, visited);
                floodFill(image, sr+1, sc, oldColor, newColor, visited);
                floodFill(image, sr, sc-1, oldColor, newColor, visited);
                floodFill(image, sr, sc+1, oldColor, newColor, visited);
            }
        }
    }

    vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int newColor) {
        vector<vector<int> > res = image;
        if (image.empty() || image[0].empty() )
            return res;
        vector<bool> visit(image[0].size(), false);
        vector<vector<bool> > visited(image.size(), visit);
        floodFill(res, sr, sc, image[sr][sc], newColor, visited);
        return res;
    }
};

int main()
{
    Solution solution;
    return 0;
}