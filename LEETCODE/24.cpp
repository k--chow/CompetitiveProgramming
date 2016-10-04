class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* previous = new ListNode(-1);
        previous->next = head;
        ListNode* ans = previous;
        ListNode* next;
        while (head && head->next)
        {
            next = head->next;
            previous->next = next;
            head->next = next->next;
            next->next = head;
            previous = head;
            head = head->next;

        }
        next = ans->next;
        return next;
    }
};
