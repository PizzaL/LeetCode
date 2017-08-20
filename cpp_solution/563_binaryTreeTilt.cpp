#include <iostream>
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
    int sum(TreeNode* root)
    {
        if (root == NULL)
            return 0;   
        return sum(root->left)+sum(root->right)+root->val;
    }
    int findTilt(TreeNode* root) {
        if (root == NULL)
            return 0; 
        return abs(sum(root->left)-sum(root->right)) + findTilt(root->left) + findTilt(root->right);
    }
};

int main()
{
	Solution solution;

	return 0;
}