/*
Merge two sorted lists.
*/

sol 1:
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* curr = new ListNode(0);
        ListNode* dummy = curr;

        while(list1 and list2)
        {
            if(list1->val<list2->val)
            {
                dummy->next = list1;
                list1=list1->next;
            }

            else
            {
                dummy->next = list2;
                list2=list2->next;
            }
            dummy = dummy->next;
        }

        if(list1)
        {
            dummy->next = list1;
        }
        if(list2)
        {
            dummy->next = list2;
        }

        return curr->next;
    }
};

________
  
sol 2

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        ListNode* list3 = nullptr;

        if(list1->val<list2->val)
        {
            list3 = new ListNode(list1->val);
            list3->next = mergeTwoLists(list1->next,list2);

        }

        else
        {
            list3 = new ListNode(list2->val);
            list3->next = mergeTwoLists(list1,list2->next);
        }

        return list3;
    }
};
