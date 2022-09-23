/*
Reverse Linked List
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head or !head->next) return head;
       ListNode* prev = nullptr;
       ListNode* curr = head;
         ListNode* next = nullptr; 
        while(curr)
        {
          next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

___
  
 class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head or !head->next) return head;
      ListNode* temp = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return temp;
        
    }
};
