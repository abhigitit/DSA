/*
House Robber
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int temp1 = 0;
        int temp2 = 0;

        for(auto& num : nums)
        {
            int temp = temp2;
            num = max(num+temp1, temp2);
            temp2 = num;
            temp1 = temp;

        }
        return temp2;
    }
};
