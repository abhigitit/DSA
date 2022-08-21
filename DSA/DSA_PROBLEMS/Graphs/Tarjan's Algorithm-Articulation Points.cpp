
/*
Articulation Points : A vertex is called an articulation point if rmeoving it and all edges associated with it, the number of
connected components in the graph increases.

Biconnectivity : A connected undirected graph is binconnected if there are no vertices whose removal disconnects the rest of the graph.
Applications : to find critical points or single point of failures.

Brute Force : Remove each vertex and perform DFS or BFS on rest of the graph and check if its connected.
TC : O(V*(V+E))


Better Algoritm: Tarjan's Algoritm

*/

