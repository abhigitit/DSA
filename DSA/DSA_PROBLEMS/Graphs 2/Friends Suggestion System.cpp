/*
Kosaraju SCC

*/

#include <bits/stdc++.h>

using namespace std;


class Network{
    map<string,vector<string>> friends;
    map<string,vector<string>> friendsT;
    stack<string> st;
    set<string> visited;
    vector<vector<string>> scc_consolidated;
    int people;
    public:
    Network()
    {
        this->people = people;
    }
    
    void createFriendsMapping(string name1, string name2)
    {
        friends[name1].push_back(name2);
    }
    
    void initializeSuggestions()
    {
        printFriendsMapping();
        buildSCC1();
        transpose();
        buildSCC2();
        printConsolidatedSCC();
    }
    
    void input(string name)
    {
        
    }
    void buildSCC1()
    {
        for(auto it:friends)
        {
            
            if(!visited.count(it.first))
            {
              dfs1(it.first);
            }
        }
    }
    void buildSCC2()
    {
        visited.clear();
        while(!st.empty())
        {
            string source = st.top();
            st.pop();
            vector<string> scc;
            if(!visited.count(source))
                dfs2(source,scc);
            if(scc.size()!=0)
                scc_consolidated.push_back(scc);
            
        }
    }
    void dfs1(string source)
    {
        visited.insert(source);
        for(auto nei:friends[source])
        {
            if(!visited.count(nei))
                dfs1(nei);
        }
        st.push(source);
    }
    
    void dfs2(string source,vector<string>& scc)
    {
        scc.push_back(source);
        visited.insert(source);
        
        for(auto nei:friendsT[source])
        {
            if(!visited.count(nei))
                dfs2(nei,scc);
        }
    }
    
    void transpose()
    {
        for(auto it:friends)
        {
            for(auto nei:it.second)
            {
                friendsT[nei].push_back(it.first);
            }
        }
    }
    
        void printFriendsMapping()
    {
        for(auto me:friends)
        {
            cout<<me.first<<" knows ";
            for(auto f:me.second)
            {
                cout<<f<<", ";
            }
            cout<<"\n";
        }
        cout<<endl;
    }
    
    void printConsolidatedSCC()
    {
        cout<<"Grouped such that everybody know everybody in the group"<<endl;
        for(int i=0;i<scc_consolidated.size();++i)
        {
            cout<<"[ ";
            for(auto j:scc_consolidated[i])
            {
                cout<<j<<", ";
            }
            cout<<" ]"<<endl;
        }
    }
    
};

int main()
{
    Network g;
    g.createFriendsMapping("Abhiteja","Jashwanth");
    g.createFriendsMapping("Abhiteja","Sidhu");
    g.createFriendsMapping("Abhiteja","Vineeth");
    g.createFriendsMapping("Abhiteja","Mounica");
    g.createFriendsMapping("Jashwanth","Sidhu");
    g.createFriendsMapping("Jashwanth","Abhiteja");
    g.createFriendsMapping("Jashwanth","Vishal");
    g.createFriendsMapping("Jashwanth","Aishwarya");
    g.createFriendsMapping("Sidhu","Jashwanth");
    g.createFriendsMapping("Sidhu","Abhiteja");
    g.createFriendsMapping("Vineeth","Kiran");
    g.createFriendsMapping("Vineeth","Santhosh");
    g.createFriendsMapping("Santhosh","Vineeth");
    g.initializeSuggestions();


    return 0;
}
