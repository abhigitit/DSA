/*
Step-By-Step Directions From a Binary Tree Node to Another

https://www.youtube.com/watch?v=BPVP_8dr7-U&ab_channel=CrackingFAANG

Can add the parent node pointer in class and make it a simple graph problem. But interviewer might not agree.
Now this tree can be converted into graph with adjacency list.

See leetcode example input
For node 2 we can store the adjacency list in the following way

{2 : [[5,'U'],[6,'L'], [4,'R']]}

Apply BFS for shortest path
O(N) TC SC
*/

class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        queue<TreeNode*> treeBFS;
        unordered_map<int,vector<pair<int,string>>> adj;
        treeBFS.push(root);
        
        while(!treeBFS.empty())
        {
            TreeNode* node = treeBFS.front();
            treeBFS.pop();
            
            if(node->left)
            {
                adj[node->left->val].push_back({node->val,"U"});
                adj[node->val].push_back({node->left->val,"L"});
                treeBFS.push(node->left);
            }
            
            if(node->right)
            {
                adj[node->right->val].push_back({node->val,"U"});
                adj[node->val].push_back({node->right->val,"R"});
                treeBFS.push(node->right);
            }
        }
        
        
        queue<pair<int,string>> graphBFS;
        graphBFS.push({startValue,""});
        set<int> seen;
        while(!graphBFS.empty())
        {
            pair<int,string> curr = graphBFS.front();
            graphBFS.pop();
            auto curr_node = curr.first;
            auto curr_path = curr.second;
            if(seen.count(curr_node))
                continue;
            else
                seen.insert(curr_node);
            
            if(curr_node==destValue)
                return curr_path;
            else
            {
                for(auto m:adj[curr_node])
                {
                    if(!seen.count(m.first))
                        graphBFS.push({m.first,curr_path + m.second});
                }
            }
            
        }
        return "";
    }
};

