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
    int findBottomLeftValue(TreeNode* root) {
        vector<TreeNode*> list(1, root);
        while ( !list.empty() )
        {
            vector<TreeNode*> children = vector<TreeNode*>();
            for (size_t i=0; i<list.size(); ++i)
            {
                if (list[i]->left)
                    children.push_back(list[i]->left);
                if (list[i]->right)
                    children.push_back(list[i]->right);
            }
            if (children.empty())
                break;
            else
                list=children;
        }
        return list[0]->val;
    }
};
int main()
{
	Solution solution;
	return 0;
}