
/*
Rearrange characters in a String such that no two adjacent characters are same
Use priortiy queue to print most frequently occuring characters alternatingly.
*/

#include <bits/stdc++.h>

using namespace std;



void rearrange(string& s)
{
    map<char,int> freq;
    priority_queue<pair<int,char>> pq;
    for(auto i:s)
    {
        freq[i]++;
    }
    
    for(auto i:freq)
    {
        pq.push(make_pair(i.second,i.first));
    }
    
    string str = "";
    pair<int,char> prev;
    prev = make_pair(-1,'#');
    while(!pq.empty())
    {
        
          pair<int,char> k = pq.top();
        pq.pop();
        str = str + k.second;
 
        if (prev.first > 0)
            pq.push(prev);

        (k.first)--;
        prev = k;
            
    }
    cout<<str;

}
int main()
{
    string s = {"aabccdee"};
    rearrange(s);
    return 0;
}
