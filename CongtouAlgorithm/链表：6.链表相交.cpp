//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        ListNode* pA = headA, * pB = headB;
        int lenA = 0, lenB = 0;
        while(pA != nullptr)
        {
            pA = pA->next;
            lenA++;
        }
        while(pB != nullptr)
        {
            pB = pB->next;
            lenB++;
        }
        pA = headA;
        pB = headB;
        if (lenA > lenB)
        {
            for (int i = 0; i < lenA - lenB; i++)
                pA = pA->next;
        }
        else
        {
            for (int i = 0; i < lenB - lenA; i++)
                pB = pB->next;
        }
        while(pA != nullptr && pB != nullptr)
        {
            if (pA == pB)
            {
                return pA;
            }
            pA = pA->next;
            pB = pB->next;
        }
        return nullptr;
    }
};
