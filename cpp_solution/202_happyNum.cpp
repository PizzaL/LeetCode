#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    bool isHappy(set<int>& appear, int n)
    {
        cout << n << endl;
        if (n == 1)
            return true;
        else if (appear.find(n) != appear.end())
            return false;
        
        appear.insert(n);
        int res=0;
        while (n)
        {
            int temp = n%10;
            res+=temp*temp;
            n/=10;
        }
        return isHappy(appear, res);
    }

    bool isHappy(int n) {
        set<int> appear; 
        return isHappy(appear, n);
    }
};

int main()
{
	Solution solution;
    cout << solution.isHappy(19);
	return 0;
}