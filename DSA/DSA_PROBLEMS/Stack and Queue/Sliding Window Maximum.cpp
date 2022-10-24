/*

Sliding Window Maximum

Intuition : Monotic decreasing double ended queue. Maintain the max number at the front of the deque.

https://www.youtube.com/watch?v=DfljaUwZsOk&t=17s&ab_channel=NeetCode

O(N)
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> mydeque;
        vector<int> res;
        int l=0,r=0;
            while(r<nums.size())
            {
                while(!mydeque.empty() and nums[r]>nums[mydeque.back()])
                mydeque.pop_back();
                
                 mydeque.push_back(r);
                
                if(l>mydeque.front())
                    mydeque.pop_front();
                
                if(r+1>=k)
                {
                   res.push_back(nums[mydeque.front()]);
                    l++;
                }
                r++;
                    
            }
        return res;
    }
};

