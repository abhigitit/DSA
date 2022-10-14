/*

Leetcode: 148

Apply merge sort
*/

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head or !head->next) return head;
       ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = head;
        
        while(fast and fast->next)
        {
            temp = slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        temp->next = nullptr;
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);
        return merge(left,right);
    }
    
    ListNode* merge(ListNode* left, ListNode* right)
    {
        
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        
        while(left and right)
        {
            if(left->val < right->val)
            {
                 curr->next = left;
                left = left->next;
            }
               else{
                   curr->next = right;
                   right = right->next;
               }
            curr=curr->next;
            
        }
        if(left)
        {
            curr->next = left;
        }
        if(right)
        {
            curr->next = right;
        }
        
        return dummy->next;
    }
};
