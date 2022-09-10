/*

Leetcode: 146

https://www.youtube.com/watch?v=7ABFKPK2hD4&t=238s&ab_channel=NeetCode

Intution: Make use of two dummy nodes left and right. Insert recently used just left to the dummy right and the least recently used always stays just right to the gummy left.

*/

class Node {
    public:
    Node* next;
    Node* prev;
    int key;
    int val;
    Node(int key,int val)
    {
        this->key = key;
        this->val = val;
        next = nullptr;
        prev = nullptr;
    }
};


class LRUCache {
public:
    int cap;
    map<int,Node*> cache;
    Node* left;
    Node* right;
    LRUCache(int capacity) {
        cap = capacity;
        left = new Node(0,0);
        right =new Node(0,0);
        left->next = right;
        right->prev = left;
        cache.clear();
    }
    
    void remove(Node* node)
    {
      Node* ltemp = node->prev;
        Node* rtemp = node->next;
        ltemp->next = rtemp;
        rtemp->prev = ltemp;
    }
    
    void insert(Node* node)
    {
        Node* rtemp = right;
        Node* ltemp = right->prev;
        
        ltemp->next = node;
        rtemp->prev = node;
        
        node->next = right;
        node->prev = ltemp;
    }
    int get(int key) {
        if(cache.find(key)!=cache.end())
        {
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end())
            remove(cache[key]);
        
        cache[key] = new Node(key,value);
        insert(cache[key]);
        
        if(cache.size()>cap)
        {
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
