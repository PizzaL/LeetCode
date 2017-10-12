#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int reverseNum = 0;
        if (x!=0 && x%10 == 0)
            return false;
        while (x > reverseNum)
        {
            reverseNum=reverseNum*10 + x%10;
            x /= 10;
        }

        cout << 99999999*99999999<< endl;
                return reverseNum == x || reverseNum/10 == x;

    }
};

int main()
{
	Solution solution;
    cout << solution.isPalindrome(9);
	return 0;
}