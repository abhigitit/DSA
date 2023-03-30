/*
leetcode : 2115
Brute force approach : https://www.youtube.com/watch?v=Xnt3uDTzsLU&ab_channel=WhatTheCode
TC:O(n^4)
*/

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        map<string,int> store;
        vector<string> res;
        int n = recipes.size();
        for(auto& i:supplies)
        {
            store[i]=1;
        }
        vector<int> pos(n,0);
        int prev = n;
        
        while(1)
        {
            bool f = 0;
            for(int i=0;i<n;++i)
            {
                if(!pos[i])
                    f=1;
            }
            if(!f) break;
            
            
            for(int i=0;i<n;++i)
            {
                if(pos[i]) continue;
                f=1;
                
                for(auto& j:ingredients[i])
                {
                    if(!store[j])
                    {
                        f=0;
                        break;
                    }
                        
                }
                
                if(f)
                {
                    store[recipes[i]]=1;
                    res.push_back(recipes[i]);
                    pos[i]=1;
                }
            }
            int cnt = 0;
            for(int i=0;i<n;++i)
            {
                if(!pos[i]) cnt++;
                
            }
            if(prev==cnt) 
                break;
            prev = cnt;
        }
        
        
       return res; 
        
        
    }
    
};
