#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findPos(vector<int>& numbers, int i, int target)
    {
        int start = i+1; 
        int end = numbers.size()-1;
        while (start < end)
        {
            int mid = (start+end)/2;
            if (numbers[mid] == target)
                return mid;
            else if (numbers[mid] > target)
                end = mid-1;
            else
                start = mid+1;
        }
        if (numbers[start] == target)
            return start;
        else 
            return -1;
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        for (size_t i=0; i<numbers.size()-1; ++i)
        {
            int pos = findPos(numbers, i, target-numbers[i]);
            if (pos > 0)
            {
                vector<int> res;
                res.push_back(i+1);
                res.push_back(pos+1);
                return res;
            }
        }
        return vector<int>();
    }
};

int main()
{
	Solution solution;
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	int target = 6;
	vector<int> res = solution.twoSum(nums, target);
	cout << res[0] << ", " << res[1] << endl;
	return 0;
}