#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void insert(vector<pair<int, int> >& resList, vector<int>& numList)
    {
        int pos = 0;
        for (size_t i=0; i<resList.size(); ++i)
        {
            int curr = max(resList[i].second, numList[pos])-min(resList[i].first, numList[pos]);
            int temp = 0;
            while (pos+temp+1 < numList.size())
            {
                int next = max(resList[i].second, numList[pos+temp+1])-min(resList[i].first, numList[pos+temp+1]);
                if (curr>next)
                {
                    pos+=temp+1;
                    temp = 0;
                    curr = next;
                } else if (curr==next)
                {
                    ++temp;
                } else
                {
                    break;
                }
            }
            resList[i].first=min( resList[i].first, numList[pos]);
            resList[i].second=max(resList[i].second, numList[pos]);
        }
    }

    void print(vector<pair<int, int> >& res)
    {
        cout << "Res set" << endl;
        for (auto& elem:res)
            cout << elem.first << " " << elem.second << endl;
    }

    vector<int> smallestRange(vector<vector<int> >& nums) {
        vector<pair<int, int> > resList;
        for (auto& num:nums[0])
            resList.push_back(pair<int, int>(num, num));
        for (auto& numList:nums)
        {
            insert(resList, numList);
            print(resList);
        }
        int size = 100000*2;
        vector<int> res(2, 0);
        for (auto& element:resList)
            if (element.second-element.first<size)
            {
                size = element.second-element.first;
                res[0] = element.first;
                res[1] = element.second;
            }
        return res;
    }
};

int main()
{
	Solution solution;
	return 0;
}