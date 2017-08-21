#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        if ( a.size() < b.size() )
            return b.size();
        else if (a==b)
            return -1;
        else return a.size();

    }
};

int main()
{
	Solution solution;
	return 0;
}