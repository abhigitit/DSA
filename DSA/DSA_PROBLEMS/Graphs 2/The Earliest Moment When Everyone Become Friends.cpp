class Solution {
    vector<int> renk;
    vector<int> parent;
    void makeset(int n)
    {
        for(int i=0;i<n;++i)
        {
            renk[i]=0;
            parent[i]=i;
        }
    }
    
    int uneon(int u,int v)
    {
        u = findParent(u);
        v = findParent(v);
        if(u==v)
            return 0;
        if(renk[u]<renk[v])
            parent[u]=v;
        else if(renk[u]>renk[v])
            parent[v]=u;
        else
        {
            parent[v]=u;
            renk[u]++;
        }
        return 1;
    }
    
    int findParent(int node)
    {
        if(node==parent[node])
             return node;
        return parent[node]=findParent(parent[node]);
    }
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(),logs.end());
        renk.resize(n);
        parent.resize(n);
        makeset(n);
        int groups=n;
        for(int i=0;i<logs.size();++i)
        {
            int u = logs[i][1];
            int v = logs[i][2];
            groups-=uneon(u,v);
            if(groups==1)
                return logs[i][0];
        }
        return -1;
    }
};
