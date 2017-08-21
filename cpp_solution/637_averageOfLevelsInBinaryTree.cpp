#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
     int val;
      TreeNode *left;
     TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        vector<TreeNode*> list;
        list.push_back(root);
        while (!list.empty())
        {
            double total = 0;
            vector<TreeNode*> children = vector<TreeNode*>();
            for (size_t i=0;i<list.size(); ++i)
            {
                total+=list[i]->val;
                if (list[i]->right)
                    children.push_back(list[i]->right);
                if (list[i]->left)
                    children.push_back(list[i]->left);
            }
            res.push_back(total/list.size());
            list = children;
        }
        return res;
    }
};

int main()
{
	Solution solution;
	return 0;
}