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
    int findMax(const vector<TreeNode*> currRow)
    {
        int max=currRow[0]->val;
        for (size_t i=1; i<currRow.size(); ++i)
        {
            if (currRow[i]->val > max)
                max = currRow[i]->val;
        }
        return max;
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (root==NULL)
            return res;
        vector<TreeNode*> currRow;
        currRow.push_back(root);
        while (!currRow.empty())
        {
            res.push_back(findMax(currRow));
            vector<TreeNode* > newRow=vector<TreeNode* >();
            for (size_t i=0;i<currRow.size();++i)
            {
                if (currRow[i]->left)
                    newRow.push_back(currRow[i]->left);
                if (currRow[i]->right)
                    newRow.push_back(currRow[i]->right);
            }
            currRow=newRow;
        }
        return res;
    }
};

int main()
{
	Solution solution;
	return 0;
}