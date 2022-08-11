
/*
Leetcode: 19
Intution: Take fast and slow pointers pointing to head and create a space of n nodes between fast and slow.
Then loop until fast becomes null so that slow stops right before the node to be removed.
TC: O(N)
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
      
       for(int i=1;i<=n+1;++i)
       {
           fast = fast->next;
       }
        while(fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};
