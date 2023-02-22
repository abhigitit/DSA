/*

Morther vertex : In DG, a vertex from which all the vertices in the graph are reachable is called mother vertex.

Intuition : Mother vertex is the last vertex to get finished in the dfs of the graph.

Also, once mother vertex is obtained, we should check if all the vertices are reachable again; there could be disconnected vertices.

O(V+E)

*/

void Graph::DFS(int s)
{
    visited[s]=true;
    cout<<s<<"\n";
    list<int>::const_iterator it;
    for(it=adj[s].begin();it!=adj[s].end();++it)
    {
        if(!visited[*it])
        DFS(*it);
    }
}

int Graph::findMother()
{
    int v = 0;
    for(int i=0;i<this->v;i++)
    {
        if(!visited[i])
        {
            DFS(i);
            v = i; // last one to end in dfs because no other vertex will mark mother vertex as visited.
        }
    }
    
    fill(visited.begin(),visited.end(),false); //re-fill the visited
    DFS(v); //dfs to verify if its really the mother vertex
    cout<<"end of dfs help"<<"\n";
    for(int i=0;i<v;++i)
    {
        if(visited[i]==false)
        return -1;
    }
    return v;
    
}
