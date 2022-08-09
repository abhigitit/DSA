/*
Leetcode : Contains Duplicate 3

Intuition: abs(nums[i]-nums[j])<=t
With one number, find the boundaries within which another number can be present.
Suppose we are on nums[j], then nums[i] lies within a specified range => nums[j]-t<=nums[i]<=nums[j]+t

Calculate the lower bound first and check if the number if within upper bound as well.

TC:O(NlogK)
SC : O(k)
*/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
      if(t<0 or k<=0) return false;
    set<long> window;
    
    for(int right = 0;right<nums.size();right++)
    {
        if(right>k) window.erase(nums[right-k-1]);
       
        auto safe = window.lower_bound((long)nums[right]-(long)t);

        if(safe!=window.end() and *safe<=(long)nums[right]+(long)t) return true;
        window.insert(nums[right]);
    }
    return false;
    }
};
