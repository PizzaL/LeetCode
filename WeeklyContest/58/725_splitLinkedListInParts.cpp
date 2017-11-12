#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <sstream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    int count(ListNode* root)
    {
        int total = 0;
        while (root)
        {
            ++total;
            root = root->next;
        }
        return total;
    }
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int total = count(root);
        if (total <=k)
        {
            vector<ListNode*> res;
            for (size_t i=0;i<k; ++i)
            {
                if (root)
                {
                    res.push_back(root);
                    ListNode* newRoot = root->next;
                    root->next = NULL;
                    root = newRoot;
                }
                else
                    res.push_back(NULL);
            }
            return res;
        } 
        else
        {
            int num = total/k;
            int s = total % k;
            vector<ListNode*> res;
            for (size_t i=0; i<k; ++i)
            {
                res.push_back(root);
                int idx = 0;
                while (idx<num-1)
                {
                    root = root->next;
                    ++idx;
                }
                if (i<s)
                    root = root->next;
                ListNode* newRoot = root->next;
                root->next = NULL;
                root = newRoot;

            }
            return res;
        } 
    }
};

int main()
{
    Solution solution;
    return 0;
}