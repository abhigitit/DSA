
/* Like Height of tree

*/

map<int,int> parentToSubCount;

int dfs(TreeNode* node) {
    if(!node) return 0;

    int left_count = dfs(node->left);
    int right_count = dfs(node->right);

    parentToSubCount[node->data] = 1 + left_count + right_count; // 1 for the parent node itself
    return parentToSubCount[node->data];
}
