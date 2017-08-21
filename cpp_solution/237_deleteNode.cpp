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
        if (node==NULL)
            return;
        else
        {
            ListNode* temp = node;
            node = node->next;
            delete(temp);
        }
    }
};
int main()
{
	Solution solution;
    solution.deleteNode(NULL);
	return 0;
}