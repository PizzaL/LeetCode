#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    struct Bigger {
        int x; 
        Bigger( int x) : x(x) {}
        bool operator()( int num)
        {
            return num>=x;
        }

    };
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int res = 0;
        for (size_t i=0; i<g.size(); ++i)
        {
            std::vector<int>::iterator pos = find_if(s.begin(), s.end(), Bigger(g[i]) );
            if (pos!=s.end())
            {
                ++res;
                s.erase(pos);
            }
            else
                break;
        }
        return res;
    }
};

int main()
{
	Solution solution;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
    vector<int> s(2,2);    
	int res = solution.findContentChildren(nums, s);
	cout << res<< endl;
	return 0;
}