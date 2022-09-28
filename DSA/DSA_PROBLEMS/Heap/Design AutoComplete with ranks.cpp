/*
Design AutoComplete with ranks.cpp

*/

#include <bits/stdc++.h>

using namespace std;

  class AutocompleteSystem {
public:
   map<string,int> history;
    priority_queue<pair<int,string>> q;
      vector<string> res1;
      vector<string> res2;
      string search;
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
       search = "";
        for(int i=0;i<sentences.size();++i)
        {
            history[sentences[i]]=times[i];
        }
        
         for(auto h:history)
            {
     cout<<h.first<<": "<<h.second<<endl;
            }
 cout<<"________"<<endl;


    }

    
    vector<string> input(char c) {

        
        if(search.size()==0)
        {
     
            for(auto h:history)
            {
                if(h.first[0]==c)
                    q.push(make_pair(h.second,h.first));
            }
             while(!q.empty())
            {
                 pair<int,string> temp = q.top();
                 res1.push_back(temp.second);
                 
                q.pop();
            }
        }
      
        else{
            res2.clear();
            int idx = search.size();
            for(auto s:res1)
            {
                if(s.size()>idx and s[idx]==c)
                {
                    res2.push_back(s);
                }
            }
        }
        search+=c;
        return search.size()<=1 and res2.empty() ? res1 : res2;
            
    }
    

};


int main(){
    vector<string> sentences = {"abhi","abhiteja","azaz","bunny","boat","board"};
    vector<int> times={5,4,5,3,2,6};
  AutocompleteSystem as = AutocompleteSystem(sentences,times);
cout<<"Give a character input"<<endl;
  vector<string> res=as.input('b');
  res = as.input('o');
  for(auto s:res)
  {
      cout<<s<<endl;
  }
    return 0;
}
