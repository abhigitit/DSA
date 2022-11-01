/*
Reorder List (143) A

Intuition 1: Recursion!
If there is no head or if there is only one element or if there are only two elements, we can return

Move the temp pointer to last second node and combine first and last node. Recursively do it for 2nd node.


Intuition 2: Reverse the second half of the linked list just like in linkedlist palindrome
*/

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head or !head->next or !head->next->next)
            return;
        
        ListNode* last = head;
        while(last->next->next)
        {
            last=last->next;
        }
        
        last->next->next = head->next;
        head->next = last->next;
        last->next = nullptr;
        
        reorderList(head->next->next);
       
    }
};
