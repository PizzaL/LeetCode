#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Greater  {
public:
    bool operator()(const pair<int, int>& a, const pair<int, int>& b)
    {
        return a.first > b.first || (a.first == b.first && a.second < b.second);
    }
};

class Solution {
public:

    void enqueue(vector<pair<int, int> >& queue, const pair<int, int>& person)
    {
        vector<pair<int, int> >::iterator it = queue.begin() + person.second;
        queue.insert(it, person);
    }

    vector<pair<int, int> > reconstructQueue(vector<pair<int, int> >& people) {
        sort(people.begin(), people.end(), Greater());
        vector<pair<int, int> > res;
        for (size_t i=0; i<people.size(); ++i)
        {
            if (res.size() == 0)
                res.push_back(people[i]);
            else
                enqueue(res, people[i]);
        }
        return res;
    }
};

int main()
{
	Solution solution;
    vector<pair<int, int> > people;
    people.push_back(make_pair(7,0));
    people.push_back(make_pair(4,4));
    people.push_back(make_pair(7,1));
    people.push_back(make_pair(5,0));
    people.push_back(make_pair(6,1));
    people.push_back(make_pair(5,2));
    solution.reconstructQueue(people);
	return 0;
}