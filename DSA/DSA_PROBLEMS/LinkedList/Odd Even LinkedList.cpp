
/*
Leetcode: 328

Intuition : Connect first element with third, second with fourth..continue
Connect last element of odd sequence to first element of even sequence.

TC:O(N)
https://www.youtube.com/watch?v=YE9ggKeHeK0&t=70s&ab_channel=TECHDOSE

*/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head or !head->next or !head->next->next)
            return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* even_head = head->next;
        
        while(even and even->next)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd= odd->next;
            even=even->next;
        }
        
        odd->next = even_head;
        
        return head;
        
    }
};
