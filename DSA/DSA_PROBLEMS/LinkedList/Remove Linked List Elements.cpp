/*
Remove Linked List Elements

Intuition : Dummy node and point it to where head is pointing because first element might be removed. prev points to dummy and curr points to head.
when we delete node, no need to update prev and when we do not delete node (i.e it can stay) we update prev.

*/

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head or (!head->next and head->val==val)) return nullptr;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* temp = dummy;
        ListNode* curr = head;
        
           while(curr)
           {
               if(curr->val==val) temp->next = curr->next;
               else temp=curr; 
               curr=curr->next;
           }
           
           return dummy->next;
    }
};
