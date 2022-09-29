/*
 Linked List Cycle II
 
 slow fast cycle =>Arithmetic distance => Floyds cycle detection
 
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* slow = head;
        ListNode* fast = head;
     
        
        while(fast and fast->next)
        {
            
           slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)
                break;
        }
        
     if(!fast or !fast->next) return NULL;
        
        while(head!=slow)
        {
           
            slow = slow->next;
            head = head->next;
        }
        
        return head;
    }
};
