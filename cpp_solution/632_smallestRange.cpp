#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void insertNum(vector<std::vector<int> >& currList, const int num)
    {
        if (currList[0][0] > num)
        {
            vector<int>& curr = currList[0];
            curr[0]=num;
            return;
        } else if (currList[0][1] >= num)
        {
            return ;
        }
        int pos = currList.size()-1;
        for (size_t i=1; i<currList.size(); ++i)
        {
            vector<int>& curr=currList[i];
            if (num < curr[0])
            {
                pos = i-1; 
                break;
            } else if (num<=curr[1])
            {
                return ;
            }
        }
        if (pos == currList.size()-1)
        {
            currList[pos][1] = num;
            return ;
        }
        vector<int>& left=currList[pos];
        vector<int>& right=currList[pos+1];
        if (right[1]-num < left[1]-left[0])
        {
            right[0] = num;
        } else
        {
            left[1] = num;
        }
    }

    void updateCurrentList(vector<vector<int> >& currList, const vector<int> nums)
    {
        if (currList.size() == 0)
        {
            for (size_t i=0; i<nums.size(); ++i)
            {
                vector<int> newRange(2, nums[i]);
                currList.push_back(newRange);
            }
            return ; 
        }
        for (size_t i=0; i<nums.size(); ++i)
        {
            insertNum(currList, nums[i]);
        }
    }

    vector<int> findSmallest(vector<vector<int> > currList)
    {
        vector<int>& s = currList[0];
        for (size_t i=0; i<currList.size(); ++i)
        {
            if (currList[i][1]-currList[i][0] < s[1]-s[0])
                s = currList[i];
        }
        return s;
    }

    vector<int> smallestRange(vector<vector<int> >& nums) {
        vector<vector<int> > currList;
        for (size_t i=0; i<nums.size(); ++i)
        {
            sort(nums.begin(), nums.end());
            updateCurrentList(currList, nums[i]);
        }
        return findSmallest(currList);
    }
};

int main()
{
	Solution solution;
	return 0;
}