/*
Copy List with Random Pointer

Intuition : We need create clone linkedlist. If we start creating clone linkedlist by traversing original LL,
we wont be able to point to a node which is not cloned (because we need to point to random nodes, not only the next).

So, we create clone nodes in one pass and store the address of them such that old node maps to new clone node.
In second pass, as all the nodes are created, we can utilize the hashmap to do required mappings.

O(N)

*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head;
        unordered_map<Node*,Node*> oldToNew;
        oldToNew[nullptr] = nullptr;
        while(curr)
        {
            Node* copy = new Node(curr->val);
            oldToNew[curr] = copy;
            curr = curr->next;

        }
        curr = head;
        while(curr)
        {
            Node* copy = oldToNew[curr];
            copy->next = oldToNew[curr->next];
            copy->random = oldToNew[curr->random];
            curr = curr->next;
        }
        return oldToNew[head];
    }
};
