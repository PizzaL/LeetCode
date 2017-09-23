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
    vector<int> travel(TreeNode* root)
    {
        vector<int> res;
        if (root == NULL)
            return res;
        res = travel(root->left);
        res.push_back(root->val);
        vector<int> rightChildren = travel(root->right);
        res.insert( res.end(), rightChildren.begin(), rightChildren.end() );
        return res;
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int> nums = travel(root);
        if (nums.size()<2)
            return -1;   // shouldn't reach here
        int res=abs(nums[1]-nums[0]);
        for (size_t i=1; i<nums.size(); ++i)
        {
            res = min(res, abs(nums[i]-nums[i-1]));
        }
        return res;
    }
};

int main()
{
	Solution solution;
	return 0;
}