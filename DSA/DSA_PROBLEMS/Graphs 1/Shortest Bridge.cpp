/*
Shortest Bridge

Intuition : Shortest distance between 2 islands. To collect the 1s in a single island, we apply dfs. Then with those coordinates, we apply multi source, multi
destination BFS to reach second islands' 1's.
For shortest path with no weights = BFS

As soon as the dfs finds the first island and returns we need to call bfs and return the shortest dis

O(N*M)

*/

