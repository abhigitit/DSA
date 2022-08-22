
/*
Articulation Points : A vertex is called an articulation point if rmeoving it and all edges associated with it, the number of
connected components in the graph increases.

Biconnectivity : A connected undirected graph is binconnected if there are no vertices whose removal disconnects the rest of the graph.
Applications : to find critical points or single point of failures.

Brute Force : Remove each vertex and perform DFS or BFS on rest of the graph and check if its connected.
TC : O(V*(V+E))


Better Algoritm: Tarjan's Algoritm
 In DFS tree, vertex u is articulation point if :
 1) u is the root of DFS tree and it has atleast two children
 2)u is not root of DFS tree  and it has a child v such that no vertex in the subtree of v is connected to ancestor of u using a backedge.(can have a backedge to u)
 
 
 leaf nodes can never be articulation points.
 Backedges are those edges which are missing in DFS tree (because of already visited through another path) and present in the graph.
 
 For each node, compute two things:
 1) Discovery Time : order in which we are visiting the nodes in DFS tree.
 2) Low Time

https://www.youtube.com/watch?v=qNVNoZJFp_g&list=PLFj4kIJmwGu3m30HfYDDufr3PZBfyngr0&index=10&ab_channel=FitCoder

*/

