/*
Dijkstra's Algorithm

Why? 
BFS is used to find the shortest path between vertices. However, a traditional BFS fails when there are weights associated with the edges.

What?
Dijkstra's Algorithm is a greedy algorithm. We have a frontier which is the set of visited nodes till now. Among that frontier nodes, we consider 
all the outgoing edges and choose the minimum weight path (total cost from the source).

MinHeap to store frontier nodes {cost,node}
A hashmap to store {node : minimum cost to the node}

Graph : A to B (10 cost), A to C (3 cost) , C to B (4 cost), C to D (2 cost)

Source A. 

1)Add {0,A} into minHeap.
2)Pop from minHeap and update minimum wt to A in hashmap as 0. {A : 0}
3)Push neighbors of A to minHeap {cost to reach B '10', B}, {cost to reach C '3', C}
4)Pop from minHeap and update minimum wt to C in hashmap as 0. {C : 3}\
5)Push neighbors of C to minHeap {cost to reach B from C + cost to reach C = 4 + 3 = '7', B}, {cost to reach D from C + cost to reach C = 2 + 3 = 5, D}
Notice how B is pushed twice into the minHeap and still now popped. minHeap can contain a node multiples times because there could be
multiple paths to it and ofcourse minimum cost will be popped.

...continue

Time Complexity:
E.log(E); E in worst case -> V^2

log(E) comes from minheap. Max size of min heap could be us adding all the edges assicated with a node as we already saw a node could be added
multiple time. When we push or pop that will be log(E).

How may time should we pop and push into the min heap? E times
For all the adges ; We are pushing all the edges into the queue and might 
pop all of them in worst case. Hence E*logE

*/



