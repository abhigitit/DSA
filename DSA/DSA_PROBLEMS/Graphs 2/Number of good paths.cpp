/*
Number of good paths

All individual nodes are good paths. If the max value frequency is >=2, then there is atleast 1 additional  good path because there
will be a path between these two maximums and ofcourse all intermediate nodes are lesser.
If there are n occurrences of maximum number, then nc2 will be the good paths created bacuse of max number.

No delete the maximum valued nodes, then apply algorithm for next maximum. But time expensive.

Union Find: Consider all the nodes as independent.
Move from least value to max value because each value gets a chance to be treated as maximum value.

Start making connections node1-node2; what is max in this component? node2; then what is the freq of node2 ?
https://www.youtube.com/watch?v=pGMQUijFLNo
*/
