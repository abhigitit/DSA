/*
https://www.youtube.com/watch?v=akwRFY2eyXs
*/


class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countAtMost(nums,k) - countAtMost(nums,k-1);
    }
    
    int countAtMost(vector<int>& arr, int k)
    {
        map<int,int> store;
        int n = arr.size();
    int left = 0;
    int right = 0;
    int count = 0;
    while(right<n)
    {
        store[arr[right]]++;
        while(store.size()>k) {
            store[arr[left]]--;
            if(!store[arr[left]]) store.erase(arr[left]);
            left++;
        }

        if(store.size()<=k)
        {
            count+=right-left+1;
        }
        right++;
    }
    return count;
    }
};
