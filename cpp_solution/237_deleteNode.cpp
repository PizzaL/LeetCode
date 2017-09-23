#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    void deleteNode(ListNode* node) {
        if (!node)
            return ;
        if (node && node->next == NULL)
            delete node;
        while (node->next)
        {
            node->val = node->next->val;
            if (node->next->next)
            {
                node = node->next;
            } else
                break;
        }
        ListNode* lastNode=node->next;
        node->next = NULL;
        delete lastNode;
    }
};

int main()
{
	Solution solution;
    solution.deleteNode(NULL);
	return 0;
}