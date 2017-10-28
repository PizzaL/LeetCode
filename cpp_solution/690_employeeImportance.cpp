#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};

class Solution {
public:
    int calImportance(map<int, Employee*>& tree, int id)
    {
        int res = tree[id]->importance;
        for (size_t i=0; i<tree[id]->subordinates.size(); ++i)
        {
            res += calImportance(tree, tree[id]->subordinates[i]);
        }
        return res;
    }

    int getImportance(vector<Employee*> employees, int id) {
        map<int, Employee*> tree;
        for (size_t i=0; i<employees.size(); ++i)
        {
            tree[employees[i]->id] = employees[i];
        }
        return calImportance(tree, id);
    }
};

int main()
{
	Solution solution;
	return 0;
}