/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * ptr = new ListNode (l1->val + l2->val);
        ListNode * next = ptr;
        
        l1 = l1->next;
        l2 = l2->next;
        int first;
        int second;
        int carrier;
        while (1)
        {
            if (l1 == NULL && l2 == NULL) break;
            carrier = (next->val)/10;
            next->val %= 10;
            
            if (l1 == NULL)
            {
                first = 0;
            }
            else
            {
                first = l1->val;
                
            }
            l1 = l1->next;
            if (l2 == NULL)
            {
                second = 0;
            }
            else
            {
                second = l2->val;
                
            }
            l2 = l2->next;
            next->next = new ListNode (first + second + carrier);
            next = next->next;
            
        }
        
        if (next->val > 9)
        {
            next->next = new ListNode(next->val/10);
            next->val %= 10;
        }
        return ptr;
    }
};