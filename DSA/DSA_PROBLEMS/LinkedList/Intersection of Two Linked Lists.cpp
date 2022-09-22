/*

Intersection of Two Linked Lists

Intuition 2: - Use extra space. Use first head and traverse through the list and store the nodes on the set.
Use second head and traverse through the list and check if the node is present in the set.

Intuition 1: - Suppose the first list has length 6 and seocnd list has length 5. Move the two head pointers by one step simultaneously. When one list's
pointer reaches null, the second list's pointer is one behind because it had length 6 and it covered only 5 until now. Now the pointer which reached null,
make it point to the other list so that it has to travel 6 to reach null and when the other pointer reaches null, make it point to the first list so it has 
5 steps to reach null. By doing this, they are going to meet at the intersection.

https://www.youtube.com/watch?v=D0X0BONOQhI&t=46s&ab_channel=NeetCode


*/
1:
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* l1 = headA;
        ListNode* l2 = headB;
        while(l1!=l2)
        {
            l1 = l1 ? l1->next : headB;
            l2 = l2 ? l2->next : headA;
        }
        return l1;
    }
};

2:
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> seen;
        ListNode* tail1 = headA;
        ListNode* tail2 = headB;
        while(tail1 and tail1->next)
        {
            tail1=tail1->next;
        }
          while(tail2 and tail2->next)
        {
            tail2=tail2->next;
        }
        if(tail1!=tail2) return nullptr;
        while(headA)
        {
          seen.insert(headA);
            headA = headA->next;
        }
          while(headB)
        {
              if(seen.count(headB))
                  return headB;
          seen.insert(headB);
            headB = headB->next;
        }
        return nullptr;
    }
};
