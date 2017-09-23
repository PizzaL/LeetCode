#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPrime( const int n)
    {
        for (size_t i=2; i<n; ++i)
            if (n%i == 0)
                return false;
        return true;
    }

    int countPrimes(int n) {
        if (n<2)
            return 0;
        int res = 0;
        for (size_t i=2; i<n; ++i)
        {
            if ( isPrime(i) )
                ++res;
        }   
        return res;
    }
};

int main()
{
	Solution solution;
    cout << solution.countPrimes(10) << endl;
	return 0;
}