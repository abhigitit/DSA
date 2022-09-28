/*
Leetcode : 489

Intuition : Concept behind the algorithm is "Spiral Backtracking"
It involves two applications.
1) Backtracking : Whenever we find an obstacle in all directions(either boundary condition / 0), we backtrack to previous cell to find another path.
2)Constrained Programming : We mark visited cells as obstacles by maintaining a visited set.

We make use of directions vectors iintialising it with right hand rule. (up,right,down,left) -> {{-1,0},{0,1},{1,0},{0,-1}};
Traverse through all the directions recursively by adding a visited cell.

Time Complexity : O(4 * (N - M)) => (N - M) 
Where N is a number of cells in the room and M is a number of obstacles
We go to every cell in the room without obstacles. A cell can be visited again while backtracking from 4 different directions.
Space Complexity : O(N - M)

A DFS recursion call is over when the robot meets an obstacle on all sides except for the side it came from previosuly.
Hence, we call goBack() after every recurive call.

turnRIght() at end of for loop is to change direction when the robot cannot move or there is an already visited cell in going direction. [if the if condition fails, we
change direction]

*/

class Solution {
public:
    vector<vector<int>> directions;
    unordered_set<string> visited;
    
    void cleanRoom(Robot& robot) {
        
        directions = {{-1,0},{0,1},{1,0},{0,-1}};
        DFS(0,0,0,robot);
    }
    void goBack(Robot& robot)
    {
        robot.turnLeft();//can use right,right,move,right,right
        robot.turnLeft();
        robot.move();
        robot.turnLeft();
        robot.turnLeft();
    }
    
    void DFS(int i,int j, int dir, Robot& robot)
    {
        
        visited.insert(to_string(i)+','+to_string(j));
        robot.clean();
        
        for(int k=0;k<4;++k)
        {
            int new_dir = (dir+k)%4;
            int new_i = i+directions[new_dir][0];
            int new_j = j+directions[new_dir][1];
            string key = to_string(new_i) +',' + to_string(new_j);
            if(!visited.count(key) and robot.move())
            {
                DFS(new_i,new_j,new_dir, robot);
                goBack(robot);
            }
            robot.turnRight();//can also use left to change direction
        }
    }
};
