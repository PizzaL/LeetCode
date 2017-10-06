#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int find(int curr, int N, bool usage[], vector<vector<int> >& beautifulNums)
    {
        if (curr > N)
            return 1;
        int res =0;
        for (size_t i=0; i<beautifulNums[curr].size(); ++i)
        {
            if (usage[beautifulNums[curr][i]])
            {
                usage[beautifulNums[curr][i]] = false;
                res += find(curr+1, N, usage, beautifulNums);
                usage[beautifulNums[curr][i]] = true;
            }
        }
        return res;
    }

    int countArrangement(int N) {
        vector<vector<int> > beautifulNums;
        beautifulNums.reserve(N+1);
        beautifulNums.push_back(vector<int>());
        for (size_t i=1; i<=N; ++i)
        {
            vector<int> beautifulNum = vector<int>();
            for (size_t j=1; j<=N; ++j)
            {
                if (i%j ==0 || j%i == 0)
                    beautifulNum.push_back(j);
            }
            beautifulNums.push_back(beautifulNum);
        }
        bool usage[16];
        for (size_t i=0; i<=N; ++i)
            usage[i] = true;
        return find(1, N, usage, beautifulNums);
    }

    
};	

int main()
{
	Solution solution;
    cout << solution.countArrangement(4) << endl; 
	return 0;
}