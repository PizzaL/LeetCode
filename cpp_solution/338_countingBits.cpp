#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
    	vector<int> res;
    	res.push_back(0);
    	if (num == 0)
    		return res;
    	int k=1;
    	while (k*2<=num)
    	{
    		int oldSize=res.size();
    		for (size_t i=0; i<oldSize; ++i)
    		{
    			res.push_back(res[i]+1);
    		}
    		k*=2;
    	}
    	for (size_t i=k; i<=num; ++i)
    	{
    		res.push_back(1+res[i-k]);
    	}
    	return res;
    }
};

int main()
{
	Solution solution;
	solution.countBits(5);
	return 0;
}