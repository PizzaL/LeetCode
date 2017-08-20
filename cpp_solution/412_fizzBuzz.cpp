#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (size_t i=1; i<=n; ++i)
        {
            if (i%3 == 0 && i%5 == 0)
                res.push_back("FizzBuzz");
            else if (i%3 == 0)
                res.push_back("Fizz");
            else if (i%5 == 0)
                res.push_back("Buzz");
            else res.push_back(to_string(i));
        }
        return res;
    }
};

int main()
{
	Solution solution;
	vector<string> res = solution.fizzBuzz(15);
	cout << res[0] << ", " << res[1] << endl;
	return 0;
}