/*
Leetcode : Contains Duplicate 3

Intuition: abs(nums[i]-nums[j])<=t
With one number, find the boundaries within which another number can be present.
Suppose we are on nums[j], then nums[i] lies within a specified range => nums[j]-t<=nums[i]<=nums[j]+t

Calculate the lower bound first and check if the number if within upper bound as well.

Suppose we are on number 9 and consider the window has numbers 6,14,9 and t is 4. Find the lower bound => 9-4 which 5 but the set would have 6,14 and the lower bound would be
6. If 6<=9+4, we return true.

Suppose we are on number 9 and consider the window has numbers 14,15,9 and t is 4. Find the lower bound => 9-4 which 5 but the set would have 14,15 and the lower bound would be
14. If 14 is not less than or equal to 9+4, we dont return true.

https://www.youtube.com/watch?v=N4LtVcQ_rik&ab_channel=CodeforCause
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
