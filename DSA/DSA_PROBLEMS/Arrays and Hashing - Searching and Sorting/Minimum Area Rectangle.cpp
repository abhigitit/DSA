/*
Minimum Area Rectangle

Add the points in the hashset and check whether we can make a square using points in the set.

*/

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        set<pair<int,int>> store;
        int area = 0;
        int res = INT_MAX;
        for(int i=0;i<points.size();++i)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];

            for(auto [x2,y2]:store)
            {
                if(store.count({x1,y2}) and store.count({x2,y1}))
                {
                    area = abs(x2-x1)*abs(y2-y1);
                    res = min(res,area);
                }
                    
            }
            store.insert({x1,y1});
        }
        return res!=INT_MAX ? res : 0;
    }
};
