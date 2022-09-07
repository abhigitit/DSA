/*

To find out single source shortest path to all other vertices.

Both Bellman FOrd and Dijkstra's algorithms fail when there are negative edge weight cycles in the graph. But bellman ford can detect negative edge weights.
Dijkstra's may or maynot give correct result.

Negative edge weight cycle: we start at a particular node and return back to the node. if the cost is negative, it means the graph has negative edge weight cycle.
eg: A->B, B->C, C->A : 2,3,-6. Cost from A to A is -1

In a positive edge, the cost to return back to the source is postive. 2,3,-3. In this case Bellman Ford will give right answer.
But it fails in the case of Negative edge weight cycle. However, Bellman Ford can detect negative edge weight cycle.

Idea behind Bellman Ford: Relax all the edges. How many times? n-1 times where n is the number of vertices and n-1 would be the max number of edges
from source to destination.

Why n-1 times? In the worst case, ordering of edges will be such that it takes n-1 times for all the edges to relax. Consider source to be first index and
destination to be last index. If there are n nodes, there could be n-1 edges to the destination in the longest path possible where all the other nodes come in between.
After every relaxation, one of the other n-1 nodes' distance can be updated and needs to be rechecked. SO perform n-1 relaxations so that all the updations happen.

https://www.youtube.com/watch?v=75yC1vbS8S8&ab_channel=takeUforward

Bellman ford algorithm is dynamic programming approach where we explore all the paths and decide which is optimal where as Dijkstras is a greedy algorithm.
What is relaxation?
Relaxation between pair of two vertices u,v : Check that current distance of u + cost of u->v < current distance of v, then change distance of v
d[v] = d[u] + cost(uv)

After performing n-1 relaxations, it is guranteed that the distance array is populated with correct shortest distances.
Then, as the final step, perform one more relaxation and validate if the distance array is changing. If its changing, then we detect a negative edge wt cycle.

https://www.youtube.com/watch?v=24HziTZ8_xo&t=9s&ab_channel=TECHDOSE

*/




