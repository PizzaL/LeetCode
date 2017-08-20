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
    int findMax(vector<int>& num, int start, int end)
    {
        int res = num[start];
        int pos = start;
        for (size_t i=start; i<=end; ++i)
        {
            if (num[i] > res)
            {
                res = num[i];
                pos = i;
            }
        }
        return pos;
    }

    TreeNode* constructTree(vector<int>&num, int start, int end)
    {
        int pos = findMax(num, start, end);
        cout << num[pos] << endl;
        TreeNode* root = new TreeNode(num[pos]);
        if (pos-1 >= start)
            root->left = constructTree(num, start, pos-1);
        if (pos+1 <= end)
            root->right = constructTree(num, pos+1, end);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructTree(nums, 0, nums.size()-1);
    }
};

int main()
{
	Solution solution;
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(6);
    nums.push_back(0);
    nums.push_back(5);
	TreeNode* root = solution.constructMaximumBinaryTree(nums);
	return 0;
}