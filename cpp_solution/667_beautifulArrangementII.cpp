#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        if (k==1)
        {
            for (size_t i=1; i<=n; ++i)
                res.push_back(i);
            return res;
        }
        res.push_back(1);
        for (size_t i=n; i>k; --i)
        {
            res.push_back(i);
        }
        int count = k/2;
        if (k%2==1)
            ++count;
        for (size_t i=1; i<count; ++i)
        {
            res.push_back(i+1);
            res.push_back(k-i+1);
        }
        if (k%2 == 0)
            res.push_back(k/2+1);
        return res;
    }
};
int main()
{
	Solution solution;
    vector<int> res = solution.constructArray(3, 2);
    for(size_t i=0; i<res.size(); ++i)
        cout << res[i] << endl;
	return 0;
}