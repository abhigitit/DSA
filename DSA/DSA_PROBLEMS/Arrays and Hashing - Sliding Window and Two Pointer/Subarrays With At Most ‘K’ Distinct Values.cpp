/*
Subarrays With At Most ‘K’ Distinct Values
https://www.youtube.com/watch?v=akwRFY2eyXs
*/
#include <bits/stdc++.h> 
int kDistinctSubarrays(vector<int> &arr, int n, int k)
{
    map<int,int> store;
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
