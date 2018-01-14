#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <sstream>
#include <unordered_set>
#include <tuple> 

using namespace std;

class Solution {
public:

    struct Virus {
        int r, c;
        int wall, neighbor;
        Virus()
            : r(0), c(0), wall(0), neighbor(0)
        {}
        Virus(int r, int c, int wall, int neighbor)
            :r(r), c(c), wall(wall), neighbor(neighbor)
        {}
    };

    bool isValid(int pos, int minV, int maxV)
    {
        return pos >= minV && pos<maxV;
    }

    const int move[2][4] = {{-1, 0, 1, 0},{0, -1, 0, 1}};
    Virus findVirus( vector<vector<int> >& grid,
                     int r, 
                     int c, 
                     int value, 
                     unordered_set<int>& visited, 
                     unordered_set<int>& neighbor )
    {
        Virus res(r, c, 0, 0);
        const int count = r*grid[0].size()+c;
        if ( visited.find(count)!=visited.end() )
            return Virus();
        grid[r][c]=value;
        visited.insert(count);
        
        for (size_t i=0; i<4; ++i)
        {
            if ( isValid(r+move[0][i], 0, grid.size() )
              && isValid(c+move[1][i], 0, grid[0].size() ) )
            {
                const int newR=r+move[0][i];
                const int newC=c+move[1][i];
                if (grid[newR][newC] == 1)
                {
                    Virus virus = findVirus(grid, newR, newC, value, visited, neighbor);
                    res.wall +=virus.wall;
                    res.neighbor += virus.neighbor;
                }
                else if (grid[newR][newC] == 0)
                {
                    ++res.wall;
                    const int newCount = newR*grid[0].size()+newC;
                    if ( neighbor.find(newCount)==neighbor.end() )
                    {
                        ++res.neighbor;
                        neighbor.insert(newCount);
                    }
                }

            }
        }
        return res;
    }

    void infect(vector<vector<int> >& grid)
    {
        vector<vector<int> > newGrid = grid;
        for (size_t i=0; i<grid.size(); ++i)
            for (size_t j=0; j<grid[0].size(); ++j)
            {
                bool flag = false;
                for (size_t k=0; k<4; ++k)
                {
                    if ( isValid( i+move[0][k], 0, grid.size() )
                      && isValid( j+move[1][k], 0, grid[0].size() ) )
                    {
                        if (grid[i+move[0][k]][j+move[1][k]]==1)
                        {
                            flag = true;
                            break;
                        }
                    }
                }
                if (flag && grid[i][j] == 0)
                    newGrid[i][j] = 1;
                else
                    newGrid[i][j] = grid[i][j];
            }
        grid.swap(newGrid);
    }

    int buildWall(vector<vector<int> >& grid)
    {
        Virus res;
        unordered_set<int> visited;
        for (size_t i=0; i<grid.size(); ++i)
            for (size_t j=0; j<grid[0].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    unordered_set<int> neighbor;
                    Virus newVirus = findVirus(grid, i, j, 1, visited, neighbor);
                    if ( newVirus.neighbor > res.neighbor )
                        res = newVirus;
                }
            }
        visited.clear();
        findVirus(grid, res.r, res.c, -1, visited, visited);
        return res.wall;
    }
    void print(vector<vector<int> >& grid)
    {
        for (auto& row: grid)
        {
            for (auto& item: row)
                cout << item << " ";
            cout << endl;
        }
    }
    
    int containVirus(vector<vector<int> >& grid) {
        int res = 0 ;
        int newWall = buildWall(grid);
        while ( newWall )
        {
            res += newWall;
            infect(grid);
            newWall = buildWall(grid);
        }
        return res;
    }
};
int main()
{
    Solution solution;
    return 0;
}