#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        return string(s.rbegin(), s.rend());
    }
};

int main()
{
	Solution solution;
	int target = 9;
	string res = solution.reverseString("target");
	cout << res<< endl;
	return 0;
}