#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (size_t i=0; i<32; ++i)
        {
            res=res*2+n%2;
            n/=2;
        }
        return res;
    }
};

int main()
{
	Solution solution;
    cout << solution.reverseBits(43261596) << endl;
	return 0;
}