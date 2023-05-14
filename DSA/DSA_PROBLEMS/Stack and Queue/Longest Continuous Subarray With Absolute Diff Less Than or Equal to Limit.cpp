/*
Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit

Monotonic Inc Dequeue
Monotonic Dec Deque
https://www.youtube.com/watch?v=LDFZm4iB7tA

*/

class Solution {
    deque<int> Inc;
    deque<int> Dec;
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int res = INT_MIN;
        int s = 0;
        for(int i=0;i<nums.size();++i) {

            while(!Inc.empty() and nums[i]<nums[Inc.back()]) Inc.pop_back();
            Inc.push_back(i);

            while(!Dec.empty() and nums[i]>nums[Dec.back()]) Dec.pop_back();
            Dec.push_back(i);


            int maxe = nums[Dec.front()];
            int mine = nums[Inc.front()];

            if(maxe-mine<=limit)
            {
                res = max(res,i-s+1);
            }
            else
            {
                s++;
                if(s>Dec.front()) Dec.pop_front();
                if(s>Inc.front()) Inc.pop_front();
            }
        }
        return res;
    }
};
