#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int powerOf2(int x)
	{
		int res = 1;
		for (size_t i=0;i<x; ++i)
		{
			res*=2;
		}
		return res;
	}

	void getValue(int h, int start, vector<bool>& bits, vector<int>& res, int maxValue)
	{
		if (h==0)
		{
			int r = 0;
			for(size_t i=0; i<bits.size(); ++i)
			{
				if (bits[i])
					r+=powerOf2(i);
			}
			if (r<maxValue)
			{
				res.push_back(r);
			}
		}
		else {
			for (size_t i=start; i<bits.size(); ++i)
			{
				if (!bits[i])
				{
					bits[i] = true;
					getValue(h-1, i+1, bits, res, maxValue);
					bits[i] = false;
				}
			}
		}
	}

	void buildTime(int h, int m, vector<string>& res)
	{
		vector<int> hours;
		vector<bool> hBits(4, false);
		getValue(h, 0, hBits, hours, 12);
		vector<int> minutes;
		vector<bool> mBits(6, false);
		getValue(m, 0, mBits, minutes, 60);
		for (auto hour:hours)
		{
			for (auto min:minutes)
			{
				string curr = to_string(hour)+":"+( min<10?"0":"")+to_string(min);
				res.push_back(curr);
			}
		}
	}

    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for (size_t i=0;i<=min(num, 4);++i)
		{
			if (num-i>=6)
				continue;
			buildTime(i, num-i, res);
		}
        return res;
    }
};

int main()
{
	Solution solution;
	vector<string> res = solution.readBinaryWatch(2);
	for(auto& str:res)
		cout << str << endl;
	return 0;
}