/*
Clone graph

Intuition : Use a hashmap to store already cloned nodes such that in dfs we dont end up re cloning the same node and return the cloned node so that 
it is directly pushed into adjacency list.

TC:O(V+E)

*/

class Solution {
public:
map<Node*,Node*> oldToNew;
    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return NULL;
        }
        if(oldToNew.count(node))
            return oldToNew[node];
        
        Node* copy = new Node(node->val);
        oldToNew[node] = copy;
        for(auto v:node->neighbors)
        {
            copy->neighbors.push_back(cloneGraph(v));
        }

        return copy;
    }
};
