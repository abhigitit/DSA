/*
Open the Lock (752) F

Inutition : BFS
Generate 8 children for every lock combination and push them into queue

O(10000)

https://www.youtube.com/watch?v=Pzg3bCDY87w
*/

class Solution {
public:
    vector<string> children(string lock)
    {
      vector<string> res;
       
      for(auto& ch : lock)
      {
          for(int i=0;i<4;++i)
          {
              string temp1 = lock;
              temp1[i] = lock[i] == '9' ? '0' : lock[i] + 1;
              res.emplace_back(temp1);
 
              string temp2 = lock;
              temp2[i] = lock[i] == '0' ? '9' : lock[i] - 1;
              res.emplace_back(temp2);
          }
      }
      return res;
    }
    int openLock(vector<string>& deadends, string target) {
        set<string> visited(deadends.begin(),deadends.end());
        if(visited.count("0000")) return -1;
        queue<pair<string,int>> BFS;
        BFS.push({"0000",0});
        
        while(!BFS.empty())
        {
            pair<string,int> curr = BFS.front();
            BFS.pop();
            string lock = curr.first;
            int turns = curr.second;
            
            if(lock==target) return turns;
            
            for(auto& l: children(lock))
            {
                if(!visited.count(l))
                {
                    visited.insert(l);
                    BFS.push({l,turns+1});
                }
            }
        }
        return -1;
    }
};
