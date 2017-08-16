#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int v = 0, h = 0;
        for (size_t i=0; i<moves.size(); ++i)
        {
            if (moves[i] == 'U')
                ++v;
            else if (moves[i] == 'D')
                --v;
            else if (moves[i] == 'L')
                --h;
            else if (moves[i] == 'R')
                ++h;
        }
        return v==0 && h ==0;
    }
};

int main()
{
	Solution solution;
	bool res = solution.judgeCircle("UDDULLRR");
	cout << res << endl;
	return 0;
}