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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return NULL;
        ListNode* res = reverseList(head->next);
        head->next = NULL;
        if (res == NULL)
            res = head;
        else
        {
            ListNode* last=res;
            while (last->next)
                last = last->next;
            last->next = head;
        }
        return res;
    }
};

int main()
{
	Solution solution;
	return 0;
}