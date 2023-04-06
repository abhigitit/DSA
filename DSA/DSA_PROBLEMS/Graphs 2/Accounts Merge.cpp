/*
 Accounts Merge
 */
class Solution {
    unordered_map<string,int> mailNode;
    vector<int> renk;
    vector<int> parent;

    void makeset(int n)
    {
        for(int i=0;i<n;++i)
        {
            parent[i]=i;
        }
    }

    int findParent(int node)
    {
        if(node==parent[node])
            return node;
        return parent[node]=findParent(parent[node]);
    }

    void uneon(int u, int v)
    {
        u = findParent(u);
        v = findParent(v);
        if(u==v) return;
        if(renk[u]<renk[v]) parent[u] = v;
        else if(renk[u]>renk[v]) parent[v] = u;
        else {
            parent[v] = u;
            renk[u]++;
        }
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        int n = accounts.size();
        int m = accounts[0].size();
        renk.resize(n);
        parent.resize(n);
        makeset(n);
        for(int i=0;i<n;++i)
        {
            for(int j=1;j<m;++j)
            {
                string email = accounts[i][j];
                if(!mailNode.count(email))
                    mailNode[email]=i;
                else
                {
                    uneon(i,mailNode[email]);
                }
            }
        }
        vector<vector<string>> combine(n);
        for(auto email:mailNode)
        {
            int idx = findParent(email.second);
            
            combine[idx].push_back(email.first);
        }
        vector<vector<string>> res;
        for(int i=0;i<n;++i)
        {
            if(combine[i].size()==0) continue;
            
            sort(combine[i].begin(),combine[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it:combine[i])
            {
                temp.push_back(it);
            }
            res.push_back(temp);
        }
return res;
    }
};
