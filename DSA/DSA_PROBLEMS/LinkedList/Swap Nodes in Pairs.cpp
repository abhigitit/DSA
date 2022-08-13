
/*
Leetcode: 24

Intution : https://www.youtube.com/watch?v=o811TZLAWOo&ab_channel=NeetCode

TC: O(n)
*/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        
        while(curr and curr->next)
        {
            // save pointers
            ListNode* next_pair = curr->next->next;
            ListNode* second = curr->next;
            
            //reverse pairs
            second->next = curr;
            curr->next = next_pair;
            prev->next = second;
            
            //update pointers
            prev = curr;
            curr = next_pair;
            
            
        }
        return dummy->next;
    }
};
