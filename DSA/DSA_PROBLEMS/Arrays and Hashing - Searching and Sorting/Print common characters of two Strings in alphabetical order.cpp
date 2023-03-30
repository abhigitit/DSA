

/*
Print common characters of two Strings in alphabetical order
Intuition : Map with char and pair
*/
#include <bits/stdc++.h>
using namespace std;
  
  
  
void common_characters(string s1, string s2, map<char, pair<int,int>> &store)
{
    
 for(auto c1: s1)
 {
     store[c1].first += 1;
 }
 for(auto c2: s2)
 {
     if(store.find(c2)!=store.end())
     store[c2].second += 1;

 }
 
}

int main()
{
   
string s1 = "abhiteja";
string s2 = "mrunali";

map<char, pair<int,int>> store;
common_characters(s1,s2,store);

for(auto s:store)
{
    int cnt = min(store[s.first].first,store[s.first].second);
    while(cnt--)
    {
        cout<<s.first<< ",";
    }
}
  return 0;
}
