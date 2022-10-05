/*
Shortest Unsorted Continuous Subarray leetcode 581

Intuition 1: Record indices before sorting and collect min and max index where num is not in right position.

Intuition 2:
*/


1:
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
      vector<pair<int,int>> srt;
        
        for(int i=0;i<nums.size();++i)
        {
            srt.push_back({nums[i],i});
        }
        
        sort(srt.begin(),srt.end());
        
        int mini=INT_MAX;
        int maxi=-1;
        
        for(int i=0;i<nums.size();++i)
        {
            int num = srt[i].first;
            int idx = srt[i].second;
            
            if(idx==i)
                continue;
            else
            {
                mini = min(mini,i);
                maxi = max(maxi,i);
            }
                
        }
        return maxi==-1 ? 0 : maxi-mini+1;
    }
};

2:
