/*
Next Greater Element I
Leetcode: 496

Intuition : To find the immediate greter element on the right, use stack
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
      unordered_map<int,int> cache;
        for(auto i:nums2)
        {
            cache[i] = -1;
        }
      
        for(auto i:nums2)
        {
            while(!st.empty() and i>st.top())
            {
                cache[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        for(int i=0;i<nums1.size();++i)
        {
            nums1[i] = cache[nums1[i]];
        }
        
        return nums1;
        
    }
};
