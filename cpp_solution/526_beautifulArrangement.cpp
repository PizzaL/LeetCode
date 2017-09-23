#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int cal(const int N)
    {
        int num=1;
        for (size_t i=2; i<=N; ++i)
        {
            if (N%i==0)
                ++num;
        }
        int res = 1;
        for (size_t i=2; i<=num; ++i)
            res*=i;
        cout << "cal=" << res << endl;
        return res;
    }
    int countArrangement(int N) {
        int res = 1;
        for (size_t i=2; i<=N; ++i)
        {
            res = res + cal(i)-1;
            cout << res << endl;
        }
        return res;
    }
};	

int main()
{
	Solution solution;
    cout << solution.countArrangement(5) << endl; 
	return 0;
}