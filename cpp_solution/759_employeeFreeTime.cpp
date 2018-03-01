#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    const int START = -1;
    const int END = 10e8+1;

    Interval intersect(const Interval& lhs, const Interval& rhs)
    {
        int start = max(lhs.start, rhs.start);
        int end = min(lhs.end, rhs.end);
        if (start>=end)
            return Interval();
        else
            return Interval(start, end);
    }

    void merge(vector<Interval>& res, const vector<Interval>& interval)
    {
        vector<Interval> r;
        int idx = 0;
        for (size_t i=0; i<interval.size();)
        {
            if (idx == res.size())
                break;
            Interval newInterval = intersect(res[idx], interval[i]);
            if (newInterval.start != newInterval.end)
            {
                r.push_back(newInterval);
            }
            if (res[idx].end < interval[i].end)
                ++idx;
            else
                ++i;
        }
        res = r;
    }

    void clean(vector<Interval>& res)
    {
        for (auto it=res.begin(); it!=res.end(); )
        {
            if (it->start == it->end)
                res.erase(it);
            else if (it->start == START)
                res.erase(it);
            else if (it->end == END)
                res.erase(it);
            else
                ++it;
        }
    }

    vector<Interval> employeeFreeTime(vector<vector<Interval> >& schedule) {
        vector<vector<Interval> > availTime;
        for (const auto& item:schedule)
        {
            vector<Interval> temp;
            for (size_t i=0; i<item.size(); ++i)
            {
                if (i==0)
                    temp.push_back(Interval(START, item[i].start) );
                else
                    temp.push_back(Interval(item[i-1].end, item[i].start) );
            }
            if (item.empty())
                temp.push_back(Interval(START, END) );
            else
                temp.push_back(Interval(item[item.size()-1].end, END) );
            availTime.push_back(temp);
        }
        vector<Interval> res(1, Interval(START, END));
        for (const auto& item:availTime)
        {
            merge(res, item);
        }
        clean(res);
        return res;
    }
};

int main()
{
	Solution solution;
	return 0;
}
