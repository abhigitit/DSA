/*

Merge K Sorted Lists.cpp 
Leetcode : 23

Intuition : Use min heap to store k elements each time.

https://www.youtube.com/watch?v=kpCesr9VXDA&t=1194s&ab_channel=TECHDOSE
*/

struct node
{
    ListNode* n;
    int idx;
    node(ListNode* n,int b)
    {
        this->n = n;
        idx=b;
    }
};

struct compare{
    bool operator()(node a, node b)
    {
        return a.n->val > b.n->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        vector<ListNode*> ptrs(k);
        priority_queue<node,vector<node>, compare> heap;
         ListNode* head=nullptr;
        ListNode* tail = nullptr;
        for(int i=0;i<k;++i)
        {
            ptrs[i] = lists[i];
            if(ptrs[i])
                heap.push(node(ptrs[i],i));
        }
        if(heap.empty()) return nullptr; 
        head = tail = heap.top().n;   
        int idx = heap.top().idx;
        heap.pop();
        ptrs[idx] = ptrs[idx]->next;
        if(ptrs[idx])
            heap.push(node(ptrs[idx],idx));
        
        while(!heap.empty())
        {
          ListNode* temp =   heap.top().n;
            idx = heap.top().idx;
            heap.pop();
            tail->next = temp;
            tail=tail->next;
            ptrs[idx] = ptrs[idx]->next;
            if(ptrs[idx])
                heap.push(node(ptrs[idx],idx));
                
        }
        return head;
        
    }
};
