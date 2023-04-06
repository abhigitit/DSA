/*

If i give you random two nodes and ask if they belong to same component?

findparent()
union()

O(4alpha) constant
similar rank-attach anyone to anyone and increment rank for chosen leader.
else attach smaller rank to higher rank.

Path compression is children having parent as root(leader). not any other.
*/


#include <bits/stdc++.h>

using namespace std;

int parent[10000];
vector<int> r(1000);

void makeset(int n)
{
    
    for(int i=1;i<=n;++i)
    {
        r[i]=0;
        parent[i]=i;
    }
}

int findParent(int node)
{
    if(node==parent[node])
        return node;
    
    return parent[node]=findParent(parent[node]);// adding parent[node]= is path compression
}

void un(int u,int v)
{
    u = findParent(u);
    v = findParent(v);
    if(u==v) return; //if parents same, return
    if(r[u]<r[v])
    {
        parent[u]=v;
    }
    else if(r[u]<r[v])
    {
        parent[v]=u;
    }
    else
    {
        parent[v]=u;
        r[u]++;
    }
}

int main()
{
makeset(7);
un(0,1);
un(1,2);
un(4,5);
un(6,7);
un(6,4);
un(6,1);
cout<<findParent(2)<<endl;
cout<<findParent(1)<<endl;
    return 0;
}
