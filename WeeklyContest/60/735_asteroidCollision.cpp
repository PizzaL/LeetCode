#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <sstream>

using namespace std;

class Solution {
public:
    bool collision(vector<int>& asteroids)
    {
        bool flag = false;
        int pos = 0;
        for (auto it=asteroids.begin(); it!=asteroids.end() && it!=asteroids.end()-1;)
        {
            auto nextIt = next(it);
            if (*it > 0 && *nextIt<0)
            {
                flag = true;
                if (*it > -*nextIt)
                {
                    asteroids.erase(nextIt);
                } 
                else if (*it < -*nextIt)
                {
                    asteroids.erase(it);
                } 
                else
                {
                    asteroids.erase(nextIt);
                    asteroids.erase(it);
                }
            }
            else
                ++it;
        }
        return flag;
    }


    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res = asteroids;
        while (collision(res))
            ;
        return res;
    }
};
int main()
{
    Solution solution;
    return 0;
}