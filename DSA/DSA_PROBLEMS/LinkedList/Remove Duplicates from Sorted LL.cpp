
/*
Leetcode 83

Intuition : Should have two elements for compairison so two conditons in while; gather next node, if same -> remove and do not update curr else update curr;

*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode* temp = head;
       
        while(temp and temp->next)
        {
            ListNode* temp2 = temp->next;
            if(temp->val==temp2->val)
                temp->next = temp2->next;
            else
                temp = temp2;
            
        }
        return head;
    }
};
