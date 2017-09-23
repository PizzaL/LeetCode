#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size()<3)
            return 0;
        int res=0;
        int i = 0, curr = 0;
        while (i<A.size())
        {
            if (curr == 0)
            {
                if (A[i]-A[i+1] == A[i+1]-A[i+2])
                {
                    curr = 3;
                    i += 3;
                } else
                ++i;
            } 
            else
            {
                if (A[i]-A[i-1] == A[i-1]-A[i-2])
                {
                    ++curr;
                    ++i;
                } 
                else
                {
                    res += (1+curr-2)*(curr-2)/2;
                    curr = 0;
                }
            }
        }
        if (curr != 0)
        {
            res += (1+curr-2)*(curr-2)/2;
        }
        return res;
    }
};

int main()
{
	Solution solution;
	return 0;
}