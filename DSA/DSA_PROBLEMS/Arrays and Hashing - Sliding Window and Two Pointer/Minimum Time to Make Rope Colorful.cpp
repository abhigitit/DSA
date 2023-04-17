/*
https://www.youtube.com/watch?v=kBH9XnQQTSY
*/
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int right = 0;
        int maxe = 0;
        int sum = 0;
        int res =0;
        while(right<colors.size()-1)
        {
            while(colors[right]==colors[right+1])
            {
                maxe = max(maxe,neededTime[right]);
                sum+=neededTime[right];
                right++;
            } 
        maxe = max(maxe,neededTime[right]);
        sum+=neededTime[right];
        res+=sum-maxe;
        right++;
        sum=0;
        maxe=0;
        }
        return res;
    }
};
