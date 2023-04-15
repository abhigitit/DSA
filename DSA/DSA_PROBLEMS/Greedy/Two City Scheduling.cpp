/*
Two City Scheduling
store cityb-citya cost in new arr.Sort arr.First n people to city b, next n to city a 
*/

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<vector<int>> greedy;
        for(int i=0;i<costs.size();++i)
        {
            int cityb = costs[i][1];
            int citya = costs[i][0];
            greedy.push_back({cityb-citya,citya,cityb});
        }
        sort(greedy.begin(),greedy.end());

        int res = 0;

        for(int i=0;i<greedy.size();++i)
        {
            if(i<greedy.size()/2)
                res+=greedy[i][2];
            else
                res+=greedy[i][1];
        }
        return res;
    }
};
