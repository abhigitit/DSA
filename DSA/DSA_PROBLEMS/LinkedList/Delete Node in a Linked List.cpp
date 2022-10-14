/*
Delete Node in a Linked List

Intuition : Copy the next value into current node, remove next node.

O(1)
*/
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
