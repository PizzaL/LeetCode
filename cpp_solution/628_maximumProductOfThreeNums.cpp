#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    map<int,int> frequency;
    int calSum(TreeNode* root){
        if (!root)
            return 0;
        int res = root->val+calSum(root->left)+calSum(root->right);
        if (frequency.find(res) != frequency.end() )
            ++frequency[res];
        else
            frequency[res]=1;
        return res;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        frequency = map<int, int>();
        calSum(root);
        int max = 0;
        for (map<int, int>::iterator it=frequency.begin(); it!=frequency.end(); ++it)
        {
            if (it->second > max)
                max = it->second;
        }
        vector<int> res;
        for (map<int, int>::iterator it=frequency.begin(); it!=frequency.end(); ++it)
        {
            if (it->second == max)
            {
                res.push_back(it->first);
            }
        }
        return res;
    }
};

int main()
{
	Solution solution;
	return 0;
}