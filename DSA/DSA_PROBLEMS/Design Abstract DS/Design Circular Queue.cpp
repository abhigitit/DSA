/*
Design Circular Queue

Dummy left right nodes
*/

class Node {
    public:
    int val;
    Node* next;
    Node* prev;
    Node(int val,Node* next,Node* prev)
    {
       this->val = val;
        this->next = next;
        this->prev = prev;
    }
};

class MyCircularQueue {
public:
    int size;
    Node* left;
     Node* right;
    MyCircularQueue(int k) {
        size = k;
        left = new Node(0,nullptr,nullptr);
        right = new Node(0,nullptr,left);
        left->next = right;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        Node* curr = new Node(value,right,right->prev);
        right->prev->next = curr;
        right->prev = curr;
        size--;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        left->next = left->next->next;
        left->next->prev = left;
        size++;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return left->next->val;
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return right->prev->val;
    }
    
    bool isEmpty() {
        return left->next == right;
    }
    
    bool isFull() {
        return size == 0;
    }
};
