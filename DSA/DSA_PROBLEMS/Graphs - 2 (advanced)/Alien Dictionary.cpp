/*
Leetcode : Alien Dictionary

Intution:

Involves topological sorting.
Given words are already sorted. Look character by character to know lexicographic ordering.
If both words have same prefix, then longer word always comes after small word (ape,apes)(we return empty string if this is false)
So lexicographic ordering is based on the first differing character of both strings.
After knowing which alphabet comes after which, we can do topological sorting to print them lexicographically.

If there is a loop( if f points to w that means f comes before w) this is not possible and ambiguous. We return empty string in this case.

We need to check and find:

-Same prefix strings ->longer one comes after smaller one
-There is no loop in ordering of alphabets
-Topographically sort the alphabets

TC: O(V+E)
SC : O(V+E)

*/

class Solution {
public:
    map<char,set<char>> adj;
    map<char,bool> visited;
    stack<char> topo;
    string res;
    string alienOrder(vector<string>& words) {
        for(auto w:words)
        {
            for(auto const &i:w) adj[i];
        }
        
        for(int i=0;i<words.size()-1;++i)
        {
             string word1 = words[i];
             string word2 = words[i+1];
            
            int min_len = min(word1.size(),word2.size());
            string w1_strip = word1.substr(0,min_len);
            string w2_strip = word2.substr(0,min_len);
            
            if(word1.size()>word2.size() and w1_strip==w2_strip)
                return "";
            
            int k = 0;
            
            while(k<min_len)
            {
                if(word1[k]!=word2[k])
                {
                     adj[word1[k]].insert(word2[k]);
                    break;
                }
                k++;

            }
            
        }
        
        for(auto a:adj)
        {
            if(DFS(a.first))
                return "";
        }
        
        while(!topo.empty())
        {
            res+=topo.top();
            topo.pop();
        }
        return res;
    }
    
    bool DFS(char s)
    {
        if(visited.find(s)!=visited.end())
            return visited[s];
        visited[s] = true;
        set<char>::const_iterator it;
        for(it = adj[s].begin();it!=adj[s].end();++it)
        {
            if(DFS(*it))
                return true;
                
        }
        visited[s] = false;
        topo.push(s);
        return false;
    }
};
