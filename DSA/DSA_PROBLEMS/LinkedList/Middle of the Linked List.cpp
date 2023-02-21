/*
Middle of the Linked List
876

Odd number of nodes, middle is present..initialize fast = head, slow = head 
When even number of nodes and second of the two is middle...initialize fast = head, slow = head 
hen even number of nodes and first of the two is middle...initialize fast = head->next, slow = head 
*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};
