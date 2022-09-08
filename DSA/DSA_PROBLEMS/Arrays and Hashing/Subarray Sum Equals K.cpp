/*

Leetcode: 560

Prefix Sum
https://www.youtube.com/watch?v=8inhayLCCHs&t=640s&ab_channel=HelloWorld
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> store;
        store[0] = 1;
        int sum = 0;
        int count = 0;
        for(int i=0;i<nums.size();++i)
        {
            
            sum+=nums[i];
            if(store.find(sum-k)!=store.end())
                count+=store[sum-k];
            
            store[sum]++;
        }
        return count;
    }
};
