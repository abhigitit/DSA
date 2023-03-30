/*
Shortest Unsorted Continuous Subarray leetcode 581

Intuition 1: Record indices before sorting and collect min and max index where num is not in right position. O(nlogn)

Intuition 2: Find minimum number of unsorted part, find max number of unsorted part and check the indices where they fit in. O(n)

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
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int low = INT_MAX;
        int high = INT_MIN;
        
        for(int i=1;i<nums.size();++i)
        {
            if(nums[i]<nums[i-1])
                low = min(low,nums[i]);
        }
        
        
         for(int i=nums.size()-2;i>=0;--i)
        {
            if(nums[i]>nums[i+1])
                high = max(high,nums[i]);
        }
        
        int l,r;
        for(l=0;l<nums.size();++l)
        {
            if(low<nums[l])
                break;
        }
        
        for(r=nums.size()-1;r>=0;--r)
        {
            if(high>nums[r])
                break;
        }
        
        return r-l<0 ? 0 : r-l+1;
    }
};
