#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        size_t res = list1.size() + list2.size();
        vector<string> resString;
        for (size_t i=0; i< list1.size(); ++i)
        {
            string& word = list1[i];
            size_t wordPos = wordPos = find(list2.begin(), list2.end(), word) - list2.begin();
            if ( wordPos != list2.size() )
            {
                if ( res > i + wordPos)
                {
                    res = i+ wordPos;
                    resString = vector<string>(1, word);
                } else if ( res == i + wordPos)
                {
                    resString.push_back(word);
                } 
            }
        }
        return resString;
    }
};

int main()
{
    vector<string> list1, list2;
	Solution solution;
	solution.findRestaurant(list1, list2);
	return 0;
}