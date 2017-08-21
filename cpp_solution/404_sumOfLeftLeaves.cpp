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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL)
            return 0;
        int res = 0;
        if (root->left != NULL && root->left->left == NULL && root->left->right == NULL)
        {
            res += root->left->val;
        }
        return res+sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};

int main()
{
	Solution solution;
	return 0;
}