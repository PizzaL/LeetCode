#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int getHours(bool hours[], int k = -1)
	{
		int res = 0;
		int p=1;
		if (k != -1)
		{
			hours[k]=true;	
		}
		for (size_t i=0; i<4; ++i)
		{
			if (hours[i])
				res+=p;
			p*=2;
		}
		if (k != -1)
		{
			hours[k]=false;	
		}
		return res;
	}
	int getMins(bool mins[], int k = -1)
	{
		int res = 0;
		int p=1;
		if (k != -1)
		{
			mins[k]=true;	
		}
		for (size_t i=0; i<6; ++i)
		{
			if (mins[i])
				res+=p;
			p*=2;
		}
		if (k != -1)
		{
			mins[k]=false;	
		}
		return res;
	}

	void getTime(bool hours[], bool mins[], int num, vector<string>& res)
	{
		if (num == 0)
		{
			string time = to_string(getHours(hours) )+":";
			int minutes = getMins(mins);
			if (minutes<10)
				time+="0"+to_string(minutes);
			else
				time+=to_string(minutes);
			cout << time << endl;
			res.push_back( time );
			return ;
		}
		for (size_t i=0; i<6; ++i)
		{
			if (mins[i] == false && getMins(mins, i) < 60)
			{
				mins[i] = true;
				getTime(hours, mins, num-1, res);
				mins[i] = false;
			}
		}
		for (size_t i=0; i<4; ++i)
		{
			if (hours[i] == false && getHours(hours, i)<12)
			{
				hours[i] = true;
				getTime(hours, mins, num-1, res);
				hours[i] = false;
			}
		}
	}

    vector<string> readBinaryWatch(int num) {
    	bool hours[4];
    	for (size_t i=0; i<4; ++i)
    		hours[i] = false;
    	bool mins[6];
    	for (size_t i=0; i<6; ++i)
    		mins[i] = false;
        vector<string> res;
        getTime(hours, mins, num, res);
        return res;
    }
};

int main()
{
	Solution solution;
	solution.readBinaryWatch(4);
	return 0;
}