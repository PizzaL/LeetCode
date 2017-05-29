#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int> >& ops) {
        int resx = m, resy = n ;
        for (size_t i=0; i<ops.size(); ++i)
        {
            vector<int>& op =ops[i];
            if ( op[0] < resx )
                resx = op[0];
            if ( op[1] < resy )
                resy = op[1];
        }
        return resx*resy;
    }
};

int main()
{
	vector<vector<int> > ops;
    vector<int> op1;
    op1.push_back(2);
    op1.push_back(2);
    ops.push_back(op1);
    vector<int> op2;
    op2.push_back(3);
    op2.push_back(3);
    ops.push_back(op2);

	Solution solution;
	cout << solution.maxCount(3, 3, ops) << endl;
	return 0;
}