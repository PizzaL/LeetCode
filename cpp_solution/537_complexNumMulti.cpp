#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<int> readStr(string& a)
    {
        istringstream sin(a);
        vector<int> res;
        int num;
        sin >> num;
        res.push_back(num);
        char plus;
        sin >> plus;
        sin >> num;
        res.push_back(num);
        return res;
    }
    string complexNumberMultiply(string a, string b) {
        vector<int> aa = readStr(a);
        vector<int> bb = readStr(b);
        return to_string(aa[0]*bb[0]-aa[1]*bb[1])+"+"+to_string(aa[0]*bb[1]+aa[1]*bb[0])+"i";
    }
};

int main()
{
	Solution solution;
	string res = solution.complexNumberMultiply("1+-1i", "1+-1i");
	cout << res << endl;
	return 0;
}