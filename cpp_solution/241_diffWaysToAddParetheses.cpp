#include <iostream>
#include <vector>
#include <algorithm>
#include <ctype.h>

using namespace std;

class Solution {
public:
    size_t findOperator(string& input, int pos)
    {
        size_t plusPos = input.find('+', pos);
        size_t multiPos = input.find('*', pos);
        size_t minusPos = input.find('-', pos);
        return min(min(plusPos, multiPos), minusPos);
    }
    vector<int> plus(vector<int>& left, vector<int>& right)
    {
        vector <int> res;
        for (auto leftVal:left)
            for (auto rightVal:right)
            {
                res.push_back(leftVal+rightVal);
            }
        return res;
    }

    vector<int> minus(vector<int>& left, vector<int>& right)
    {
        vector <int> res;
        for (auto leftVal:left)
            for (auto rightVal:right)
            {
                res.push_back(leftVal-rightVal);
            }
        return res;
    }

    vector<int> multi(vector<int>& left, vector<int>& right)
    {
        vector <int> res;
        for (auto leftVal:left)
            for (auto rightVal:right)
            {
                res.push_back(leftVal*rightVal);
            }
        return res;
    }

    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        int pos = findOperator(input, 0);
        if (pos == -1)
        {
            res.push_back( stoi( input.c_str() ) );
            return res;
        }

        while (pos != -1)
        {
            vector<int> left = diffWaysToCompute( input.substr(0, pos) );
            vector<int> right = diffWaysToCompute( input.substr(pos+1, input.length()-pos-1) );
            vector<int> newRes;
            if (input[pos] == '+')
            {
                newRes = plus(left, right);
            } 
            else if (input[pos] == '-')
            {
                newRes = minus(left, right);
            } else if (input[pos] == '*')
            {
                newRes = multi(left, right);
            } else {
                cout << "Invalid input=" << input << endl; 
            }
            pos = findOperator(input, ++pos);
            res.insert( res.end(), newRes.begin(), newRes.end() );
        }
        return res;   
    }
};

int main()
{
	Solution solution;
    vector<int> res = solution.diffWaysToCompute("11");
	for (auto val:res)
        cout << val << ", ";
    return 0;
}