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
    TreeNode* convert(TreeNode* root, int& sum)
    {
        if (root == NULL)
            return NULL;
        root->right = convert(root->right, sum);
        root->val += sum;
        sum = root->val;
        root->left = convert(root->left, sum);
        return root;
    }

    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        return convert(root, sum);
    }
};

int main()
{
	Solution solution;
	return 0;
}