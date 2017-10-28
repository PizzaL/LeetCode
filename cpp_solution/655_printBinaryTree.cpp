#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void printRow(TreeNode* root, vector<vector<string> >& res, int r, int c)
    {
        if (res.size()<=r)
        {
            int count = 1;
            if (res.size() != 0)
                count = res[0].size()*2+1
            vector<string> newRow("", )
        }
    }

    vector<vector<string>> printTree(TreeNode* root) {
        vector<vector<string> > res;
        printRow(TreeNode* root, vector<vector<string> >& res, 0, 0);
        return res;
    }
};

int main()
{
	Solution solution;
    cout << solution.isPalindrome(9);
	return 0;
}