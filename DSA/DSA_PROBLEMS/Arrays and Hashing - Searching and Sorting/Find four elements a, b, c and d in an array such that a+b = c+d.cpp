/*
Find four elements a, b, c and d in an array such that a+b = c+d

Use map and store the sum.

O(n^2)
*/

#include <bits/stdc++.h>
using namespace std;

#define loop(n) for(int i = 0; i < n; ++ i)

vector<vector<int>> find_abcd(vector<int>& input)
{
    vector<vector<int>> res;
    map<int,pair<int,int>> store;
    int n= input.size();
    loop(n)
    {
        for(int j=i+1;j<n;++j)
        {
            int sum = input[i] + input[j];
            if(store.find(sum)==store.end())
            store[sum] = make_pair(input[i],input[j]);
            else
            {
                pair<int,int> temp= store[sum];
                res.push_back({temp.first,temp.second});
                res.push_back({input[i],input[j]});
            }
        }
    }
    return res;
}

int main()
{
 
    vector<int> input = {1,5,4,2};
    vector<vector<int>> res = find_abcd(input);
    for(auto i:res)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
