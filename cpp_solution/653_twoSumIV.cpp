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
    vector<int> travelTree(TreeNode* root)
    {
        vector<int> res;
        if (root == NULL)
            return res;
        res = travelTree(root->left);
        res.push_back(root->val);
        vector<int> rightChild = travelTree(root->right);
        res.insert(res.end(), rightChild.begin(), rightChild.end());
        return res;
    }

    bool findNum(TreeNode* root, int num)
    {
        if (root == NULL)
            return false;
        else if (root->val == num)
            return true;
        else if (root->val > num)
            return findNum(root->left, num);
        else 
            return findNum(root->right, num);
    }
    bool findTarget(TreeNode* root, int k) {
        if (root == NULL)
            return false;
        vector<int> nums=travelTree(root);
        for (size_t i=0; i<nums.size(); ++i)
        {
            if ( k!=nums[i]*2 && findNum(root, k-nums[i]) )
                return true;
        }
        return false;
    }
};

int main()
{
	Solution solution;
	return 0;
}