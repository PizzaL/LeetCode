#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool findRes(vector<int>& bits, int start)
    {
        if (bits.size() == start)
            return false;
        else if (start == bits.size()-1)
            return bits[start] == 0;
        if (bits[start]==0)
            return findRes(bits, start+1);
        else 
            return findRes(bits, start+2);
    }

    bool isOneBitCharacter(vector<int>& bits) {
        return findRes(bits, 0);  
    }
};

int main()
{
	Solution solution;
	return 0;
}