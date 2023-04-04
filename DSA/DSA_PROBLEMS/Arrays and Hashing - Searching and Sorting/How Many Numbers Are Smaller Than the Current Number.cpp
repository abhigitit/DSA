/*
 How Many Numbers Are Smaller Than the Current Number
 
 count frequency and do prefix sum
 */

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> prefix(101,0);
        vector<int> res;
        for(auto i:nums)
        {
            prefix[i]++;
        }
        
        int running_sum = prefix[0];
        for(int i=1;i<prefix.size();++i)
        {
            running_sum+=prefix[i];
            prefix[i] = running_sum;
        }
        
        for(auto i:nums)
        {
            res.push_back(prefix[i-1]);
        }
        return res;
    }
};
