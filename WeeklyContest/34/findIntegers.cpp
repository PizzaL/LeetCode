#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    map<int, int> numMap;
    int findIntegers(int num) {
        if (num == 0)
            return 1;
        if (num == 1)
            return 2;
        if (num == 2)
            return 3;
        int length = 0;
        int temp = num;
        while (temp)
        {
            temp = temp / 2;
            ++length;
        }
        int num2 = 1;
        int tempLength = length;
        while (tempLength > 2)
        {
            num2 = (num2 << 1) +1;
            --tempLength;
        }
        int num1 = 0;
        if ( ( (num >> (length-2) ) & 1) == 1)
            num1 = num2 >> 1;
        else
            num1 = num - (num >> (length-2) << (length-2) );
        if (numMap.find(num1) ==  numMap.end() )
        {
            numMap[num1] = findIntegers(num1);
        }
        if (numMap.find(num2) == numMap.end() )
        {
            numMap[num2] = findIntegers(num2);
        }
        return numMap[num1] + numMap[num2];
    }
};

int main()
{
	Solution solution;
	cout << solution.findIntegers( 4 ) << endl;
	return 0;
}