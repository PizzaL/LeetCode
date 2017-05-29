#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
    	map<int, int> allNums;
    	for (size_t i=0; i<nums.size(); ++i)
    	{
    		if ( allNums.find(nums[i]) != allNums.end() )
    		{
    			++allNums[nums[i]];
    		} else 
    		{
    			allNums[nums[i]] = 1;
    		}
    	}
    	typedef map<int, int>::iterator IIT;
    	int length = 0;
    	for ( IIT it = allNums.begin(); it != allNums.end(); ++it )
    	{
    		IIT firstNum = it;
    		IIT secondNum = next(it, 1);
    		if (secondNum == allNums.end() )
    			break;
    		if ( firstNum->first - secondNum->first == 1
    		  || secondNum->first - firstNum->first == 1 )
    		{
    			length = max(length, firstNum->second + secondNum->second);
    		}
    	}
    	return length;
    }
};

int main()
{
	vector<int> nums;
	nums.push_back(1);

	Solution solution;
	cout << solution.findLHS(nums) << endl;
	return 0;
}