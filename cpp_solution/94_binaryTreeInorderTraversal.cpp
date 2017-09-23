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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL)
            return res;
        res = inorderTraversal(root->left);
        res.push_back(root->val);
        vector<int> rightChildren=inorderTraversal(root->right);
        res.insert(res.end(), rightChildren.begin(), rightChildren.end());
        return res;
    }
};

int main()
{
	Solution solution;
	return 0;
}