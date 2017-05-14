#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        map<int, vector<int> > tree;
        for (size_t i=0; i< ppid.size(); ++i)
        {
            if (tree.find(ppid[i]) != tree.end() )
            {
                vector<int>& children = tree[ppid[i]];
                children.push_back(pid[i]);
            }
            else 
            {
                vector<int> children;
                children.push_back(pid[i]);
                tree[ppid[i]] = children;
            }
        }
        vector<int> res;
        queue<int> q;
        q.push(kill);
        while ( !q.empty() )
        {
            res.push_back(q.front());
            for (size_t i=0; i<tree[q.front()].size(); ++i)
            {
                q.push(tree[q.front()][i]);
            }
            q.pop();
        }
        return res;
    }
};

int main()
{

	return 0;
}