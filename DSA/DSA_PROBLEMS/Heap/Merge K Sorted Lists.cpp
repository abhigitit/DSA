/*

Merge K Sorted Lists.cpp 
Leetcode : 23
and AE
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

_______
    
 Vector of vectors
 
 using namespace std;

struct compare
{
bool operator()(vector<int>& a,vector<int>& b)
{
  return a[0]>b[0];
}
};
vector<int> mergeSortedArrays(vector<vector<int>> arrays) {
  int k = arrays.size();
  vector<int> res;
  
  priority_queue<vector<int>, vector<vector<int>>, compare> heap;
  for(int i=0;i<k;++i)
    {
     heap.push({arrays[i][0],i,0});
    }

 while(!heap.empty())
   {
     vector<int> temp = heap.top();
     heap.pop();
     int val = temp[0];
     int vec_idx = temp[1];
     int curr_idx = temp[2];
     int next_idx = curr_idx+1;
     res.push_back(val);
     if(next_idx<arrays[vec_idx].size())
     {
       heap.push({arrays[vec_idx][next_idx], vec_idx,next_idx});
     }
   }
  return res;
}
