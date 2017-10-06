#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <sstream>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int> >& edges) {
        map<int, int> parents;
        for (size_t i=0; i<edges.size(); ++i)
        {
            int parent = edges[i][0];
            int child = edges[i][1];
            if ( parents.find(child)!=parents.end() 
              || ( parents.find(parent) != parents.end() 
                && parents.find(parent)->second == child ) )
                return edges[i];
            else
                parents[child] = parent;
        }
    }
};
      
int main()
{
    return 0;
}