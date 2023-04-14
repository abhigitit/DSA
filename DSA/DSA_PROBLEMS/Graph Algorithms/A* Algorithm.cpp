/*
AE
The A* algorithm is generally considered to be better than Dijkstra's algorithm in certain situations because it incorporates a heuristic function that guides the search towards the goal node more efficiently.

Dijkstra's algorithm is a shortest path algorithm that works by expanding nodes in all directions equally until it reaches the goal node. 
It does not take into account any information about the goal node, 
which can make it inefficient in cases where there are multiple possible paths to the goal node and some paths are shorter than others.

A* algorithm, on the other hand, incorporates a heuristic function that estimates the distance between a given node and the goal node. 
By using this heuristic, the algorithm can prioritize searching in the direction that is most likely to lead to the goal node, 
which can reduce the number of nodes that need to be expanded and improve the overall efficiency of the search.

Overall, the A* algorithm can be more efficient than Dijkstra's algorithm in situations where there are multiple possible paths to the goal node, 
and where there is additional information available about the goal node that can be used to guide the search. 
However, in cases where all paths have the same cost, or when the cost of each path is known beforehand, 
Dijkstra's algorithm may be just as efficient or even more efficient than A*.

To be continued..
*/


#include <bits/stdc++.h>
using namespace std;


class Node
{
    public:
    int i;
    int j;
    int G; //minimum distance till this Node
    int F; //estimated distance to destination from this Node
    Node* parent; //to backtrack path
    
    Node(int i,int j)
    {
        this->i = i;
        this->j = j;
        this->G = 1e9;
        this->F = 1e9;
        this->parent = nullptr;
    }
};

class compare{
    public:
    bool operator()(Node* a, Node* b)
    {
        return a->F > b->F;
    }
};

int calculateHeuristic(Node* startNode, Node* endNode)
{
    int startRow = startNode->i;
    int startCol = startNode->j;
    int endRow = endNode->i;
    int endCol = endNode->j;
    
    return abs(startRow-endRow) + abs(startCol-endCol); //heuristic considered is manhattan distance to destination node
}
vector<vector<int>> findPath(vector<vector<int>>& grid, int startRow, int startCol, int endRow, int endCol)
{
    vector<vector<Node*>> nodes;
    priority_queue<Node*,vector<Node*>, compare> minHeap;
    for(int i=0;i<grid.size();++i)
    {
        vector<Node*> temp;
        for(int j=0;j<grid[i].size();++j)
        {
            Node* node = new Node(i,j);
            temp.push_back(node);
        }
        nodes.push_back(temp);
    }
    Node* startNode = nodes[startRow][startCol];
    Node* endNode = nodes[endRow][endCol];
    startNode->G = 0;
    startNode->F = startNode->G  + calculateHeuristic(startNode,endNode); //F = G + H
    minHeap.push(startNode);
    while()
    
    //Continue Later
    
    
    
    return constructPath();
    
    
    
}



int main()
{
    vector<vector<int>> grid = {{1,1,0,1},{0,1,1,0},{1,1,0,0},{0,1,1,0}};
    vector<vector<int>> path = findPath(grid,0,1,3,2);
    for(int i=0;i<path.size();++i)
    {
        
        for(int j=0;j<path[i].size();++j)
        {
            cout<<i<<","<<j<<endl;
        }
    }
    return 0;
}
