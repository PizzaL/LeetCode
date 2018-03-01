#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Project {
    int profit, capital;
    Project(int profit, int capital) 
        : profit(profit), capital(capital)
    {}
};

bool operator<(const Project& lhs, const Project& rhs)
{
    return lhs.profit<rhs.profit || (lhs.profit==rhs.profit && lhs.capital<rhs.capital);
}

class Solution {
public:


    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        priority_queue<Project> projects;
        for (size_t i=0; i<k; ++i)
        {
            int idx = 0;
            for (auto it=Capital.begin(); it!=Capital.end(); )
            {
                if (*it<=W)
                {
                    projects.push(Project(Profits[idx], Capital[idx]));
                    Capital.erase(it);
                    Profits.erase(Profits.begin()+idx);
                }
                else
                {
                    ++it;
                    ++idx;
                }
            }
            if (projects.empty())
                return W;
            Project newProject = projects.top();
            projects.pop();
            W+=newProject.profit;
        }
        return W;
    }
};

int main()
{
	Solution solution;
	return 0;
}
