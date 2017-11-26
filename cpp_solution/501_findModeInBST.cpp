#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    void preorder(TreeNode* root, map<int, int>& count)
    {
        if (!root)
        {
            return ;
        }
        if (count.find(root->val)!=count.end())
        {
            ++count[root->val];
        }
        else
        {
            count[root->val] = 1;
        }
        preorder(root->left, count);
        preorder(root->right, count);
    }

    vector<int> findMode(TreeNode* root) {
        map<int, int> count;
        preorder(root, count);
        map<int, vector<int> > res;
        for (auto& item:count)
        {
            if ( res.find(item.second)!=res.end() )
            {
                res[item.second].push_back(item.first);
            } 
            else
            {
                res[item.second] = vector<int>(1, item.first);
            }
        }
        if (!res.empty())
            return res.rbegin()->second;
        else
            return vector<int>();
    }
};
int main()
{
	Solution solution;
	return 0;
}