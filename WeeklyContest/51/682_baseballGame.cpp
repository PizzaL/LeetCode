#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <sstream>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> res; 
        for (size_t i=0; i<ops.size(); ++i)
        {
            string& op = ops[i];
            if (op == "+")
            {
                int last = res.size()-1;
                res.push_back(res[last-1]+res[last]);
            }
            else if (op == "D")
            {
                int last = res.size()-1;
                res.push_back(res[last]*2);
            }
            else if (op == "C")
            {
                res.erase(res.end()-1);
                cout << res.size() << endl;
            }
            else
            {
                //  integer
                istringstream sin(op);
                int num; 
                sin >> num;
                res.push_back(num); 
            }
        }
        int result = 0;
        for (size_t i=0; i<res.size(); ++i)
            result+= res[i];
        return result;
    }
};
      
int main()
{
    return 0;
}