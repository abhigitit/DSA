/*
Serialize and Deserialize Binary Tree
*/

class Codec {
public:

    vector<string> serial;
    vector<string> deserial;
    int i=0;
    string serialize(TreeNode* root) {
        DFS(root);
        string res = serial[0];
        for(int i=1;i<serial.size();++i)
        {
            res+= "," + serial[i];
        }
        return res;
    }

    void DFS(TreeNode* root)
    {
        if(!root)
        {
           serial.push_back("N");
            return;
        }
        serial.push_back(to_string(root->val));
        DFS(root->left);
        DFS(root->right);
    }
     TreeNode* DFS2()
       {
           if(deserial[i]=="N")
           {
               i++;
               return nullptr;
           }
           TreeNode* node;
               if(deserial[i]!="N")
                   node = new TreeNode(stol(deserial[i]));
           i++;
           node->left = DFS2();
           node->right = DFS2();
           return node;
       }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
       while (ss.good()) {
        string substr;
        getline(ss, substr, ',');
        deserial.push_back(substr);
       }
           return DFS2();

    }
};
