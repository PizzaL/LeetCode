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
    TreeNode* find(TreeNode* root, int key)
    {
        if (!root)
        {
            return NULL;
        } else if (root->val == key)
        {
            return root;
        } else if (root->val < key)
        {
            return find(root->right, key);
        } else 
            return find(root->left, key);
    }

    TreeNode* findLeftLargestP(TreeNode* root)
    {
        TreeNode* node = root->left;
        TreeNode* parent = root;
        while (node->right)
        {
            parent = node;
            node = node->right;
        }
        return parent;
    }

    TreeNode* findRightSmallestP(TreeNode* root)
    {
        TreeNode* node = root->right;
        TreeNode* parent = root;
        while (node->left)
        {
            parent = node;
            node = node->left;
        }
        return parent;
    }

    TreeNode* findParent(TreeNode* root, TreeNode* node)
    {
        if (root == node)
            return NULL;
        else if (root->left == node || root->right == node)
            return root;
        else if (root->val >node->val)
            return findParent(root->left, node);
        else
            return findParent(root->right, node);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* node = find(root, key);
        if (!node)
            return root;
        else if (node->left)
        {
            TreeNode* leftLargestP = findLeftLargestP(node);
            if (leftLargestP == node)
            {
                TreeNode* tempNode = node->left;
                node->val = tempNode->val;
                leftLargestP->left = tempNode->left;
                delete tempNode;
            } 
            else
            {
                TreeNode* tempNode = leftLargestP->right;
                node->val = tempNode->val;
                leftLargestP->right = tempNode->left;
                delete tempNode;
            }
        } 
        else if (node->right)
        {
            TreeNode* rightSmallestP = findRightSmallestP(node);
            if (rightSmallestP == node)
            {
                TreeNode* tempNode = node->right;
                node->val = tempNode->val;
                rightSmallestP->right = tempNode->right;
                delete tempNode;
            }
            else
            {
                TreeNode* tempNode = rightSmallestP->left;
                node->val = tempNode->val;
                rightSmallestP->left = tempNode->right;
                delete tempNode;
            }
        } else
        {
            // delete Node it self
            TreeNode* parent = findParent(root, node);
            if (parent == NULL)
            {
                // node is root;
                delete node;
                root = NULL;
            }
            else
            {
                if (parent->left == node)
                {
                    parent->left = NULL;
                } 
                else
                {
                    parent->right = NULL;
                }
                delete node;
            }
        }
        return root;
    }
};      

int main()
{
	Solution solution;
	return 0;
}



