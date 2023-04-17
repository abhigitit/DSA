/*
Minimum Area Rectangle

Add the points in the hashset and check whether we can make a square using points in the set.

*/

int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> mp;
        int res = INT_MAX;
        
        for(const auto& point : points)
            mp[point[0]].insert(point[1]);
        
        for(int i=0; i<points.size()-1; i++)
        {
            for(int j=i+1; j<points.size(); j++)
            {
                if(points[i][0] == points[j][0] || points[i][1] == points[j][1])
                    continue;
                if(mp[points[i][0]].count(points[j][1]) && mp[points[j][0]].count(points[i][1]))
                    res = min(res, abs(points[i][0] - points[j][0]) * abs(points[i][1] - points[j][1]));
            }
        }
        if(res == INT_MAX)
            return 0;
        return res;
    }


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
