//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* virutalHead = new ListNode(0, head);
        ListNode* cur = virutalHead;
        ListNode* del = nullptr;
        while (cur->next != nullptr)
        {
	        if (cur->next->val == val)
	        {
                del = cur->next;
                cur->next = cur->next->next;
                delete(del);
	        }
            else
            {
                cur = cur->next;
            }
        }
        return virutalHead->next;
    }
};