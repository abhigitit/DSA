
/*
Lowest Common Ancestor of a Binary Tree III.cpp
It is just a variation of Intersection of LinkedList!
*/



class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* a = p;
        Node* b = q;
        while(a != b) {
            a = a == nullptr ? q : a->parent;
            b = b == nullptr ? p : b->parent;  
        }
        return a;
    }
};
