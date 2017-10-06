#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <sstream>

using namespace std;

class Solution {
public:
    string nextClosestTime(string time) {
        vector<char> digits;
        digits.push_back(time[0]);
        digits.push_back(time[1]);
        digits.push_back(time[3]);
        digits.push_back(time[4]);
        sort( digits.begin(), digits.end() );
        if ( time[4] < time[3])
        {
            int i= 0;
            while (digits[i]<time[4])
                ++i;
            time[4]=digits[i];
            return time;
        }
        else if ( time[3] < time[1] )
        {
            if (time[1]<time[4])
            {
                char ch = time[1];
                time[1]=time[4];
                time[3]=digits[0];
                time[4]=digits[0];
                return time;
            } else if (time[1] == time[4])
            {
                
            }
        }
        
    }
};
      
int main()
{
    return 0;
}