/*
Reconstruct Itinerary
https://www.youtube.com/watch?v=WYqsg5dziaQ
*/


class Solution {

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
         stack<string> order;
        unordered_map<string,multiset<string>> adj;
        vector<string> res;
        int n=tickets.size();
        for(int i=0;i<n;++i)
            adj[tickets[i][0]].insert(tickets[i][1]);
        order.push("JFK");
        while(!order.empty())
        {
            string src = order.top();
            if(adj[src].size()==0)
            {
                res.push_back(src);
                order.pop();
                
            }
            else
            {
            auto nei = adj[src].begin();
            order.push(*nei);
            adj[src].erase(nei);
            }
           
        }

        reverse(res.begin(),res.end());
        return res;
    }
};
