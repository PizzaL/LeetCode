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
    string tree2str(TreeNode* t) {
        if (t == NULL)
            return string();
        if (t->left == NULL)
        {
            if (t->right == NULL)
            {
                return to_string(t->val);
            } 
            else
            {
                return to_string(t->val)+"()("+tree2str(t->right)+")";
            }
        }
        else
        {
            if (t->right == NULL)
                return to_string(t->val)+"("+tree2str(t->left)+")";
            else
                return to_string(t->val)+"("+tree2str(t->left)+")("+tree2str(t->right)+")";
        }
    }
};

int main()
{
	Solution solution;
	return 0;
}