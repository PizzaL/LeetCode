#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version)
{
    if (version >=1702766719 )
        return true;
    return false;
}

class Solution {
public:
    long badVersion(const long start, const long end)
    {
        if (start == end)
            return start;
        const long mid = (start+end)/2;
        cout << "start=" << start << "mid=" << mid << "end=" << end << endl;
        if (isBadVersion(mid))
            return badVersion(start, mid);
        else
            return badVersion(mid+1, end);

    }
    long firstBadVersion(long n) {
        return badVersion(1, n);
    }
};

int main()
{
    Solution solution;
    cout << solution.firstBadVersion(2126753390) << endl;
	return 0;
}