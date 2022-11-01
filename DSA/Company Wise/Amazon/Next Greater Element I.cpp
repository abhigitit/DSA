/*
Next Greater Element I
Leetcode: 496

Intuition : To find the immediate greter element on the right, use stack
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> nextGreat;
        stack<int> monoD;
        vector<int> res;
        for(auto& num: nums2)
        {
            while(!monoD.empty() and num>monoD.top())
            {
                nextGreat[monoD.top()] = num;
                monoD.pop();
            }
            
            monoD.push(num);
        }
        
         while(!monoD.empty())
         {
            nextGreat[monoD.top()] = -1;
             monoD.pop();
         }
        
        for(auto& num: nums1)
        {
            res.push_back(nextGreat[num]);
        }
        
        return res;
    }
};
