/*

Race Car
Intuition : Graph and BFS

https://www.youtube.com/watch?v=DBJPWJr5zZ4&ab_channel=CrackingFAANG
We need to keep track of few things => Curr num of moves, curr position, curr speed

TC: O(logT) as our speed is doubling each time and T is the target.

*/

class Solution {
public:
    int racecar(int target) {
        
        queue<vector<int>> BFS;
        set<pair<int,int>> visited;
        
        BFS.push({0,0,1});
        
        while(!BFS.empty())
        {
            vector<int> temp = BFS.front();
            BFS.pop();
            int moves = temp[0];
            int position = temp[1];
            int speed = temp[2];
            if(position==target)
                return moves;
            
            if(visited.count({position,speed}))
                continue;
            if (abs(position) > 2 * target) continue;
            else
            {
                visited.insert({position,speed});
                
                BFS.push({moves+1,position+speed,2*speed});
                
                if((position+speed >target and speed>0 ) or (position+speed <target and speed<0))
                {
     
                    BFS.push({moves+1,position,(speed>0) ? -1 : 1});
                }
            }
        }
        
        return 0;
    }
};
