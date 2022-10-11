/*
Longest Consecutive Sequence
*/


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> cache(nums.begin(),nums.end());
        
        int res=0;
        int curr_streak=1;
        int temp;
        for(auto i:cache)
        {
            if(!cache.count(i-1))
            {
                temp = i;
                curr_streak=0;
            }
            
            while(cache.count(temp))
            {
                curr_streak++;
                temp++;
            }
            
            res = max(curr_streak,res);
        }
        
        
        return res;
    }
};
