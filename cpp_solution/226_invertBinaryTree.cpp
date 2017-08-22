#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return NULL;
        TreeNode* left=root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(left);
        return root;
    }
};

int main()
{
	Solution solution;
	return 0;
}