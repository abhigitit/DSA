/*

Leetcode: 325

*/

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        map<long long,int> store;
        vector<pair<int,int>> help;
        store[0]=-1;
        long long sum = 0;
        int res = 0;
        for(int i=0;i<nums.size();++i)
        {
            sum+=nums[i];
            
            if(store.find(sum-k)!=store.end())
            {
              help.push_back({store[sum-k],i});
            }
            
            if(store.find(sum)==store.end())
            store[sum]=i;
        }
        for(int i=0;i<help.size();++i)
        {
            res = max(res,help[i].second-help[i].first);
        }
            
        
        return res;

    }
};
