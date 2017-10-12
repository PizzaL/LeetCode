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
    void deleteNode(TreeNode* root)
    {
        if (root)
        {
            deleteNode(root->left);
            deleteNode(root->right);
            delete root;
        }
    }

    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root)
            return root;
        else if (root->val < L)
        {
            deleteNode(root->left);
            TreeNode* node = root->right;
            if (node)
            {
                root->left = node->left;
                root->right = node->right;
                root->val = node->val;
                delete node;
                return trimBST(root, L, R);
            } else
            {
                delete root;
                return NULL;
            }

        }
        else if (root->val > R)
        {
            deleteNode(root->right);
            TreeNode* node = root->left;
            if (node)
            {
                root->left = node->left;
                root->right = node->right;
                root->val = node->val;
                delete node;
                return trimBST(root, L, R);
            } else
            {
                delete root;
                return NULL;
            }
        } else
        {
            root->left = trimBST(root->left, L, R);
            root->right = trimBST(root->right, L, R);
            return root;
        }
    }
};

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(2);
	Solution solution;
    solution.trimBST(root, 1, 2);
	return 0;
}