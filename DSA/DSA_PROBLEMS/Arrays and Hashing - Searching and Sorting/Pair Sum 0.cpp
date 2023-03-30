/*
Coding Ninjas : Zero Pair Sum
Add all elements into map with frequencies.
Loop through map and if we are on number 1, check if -1 is present and multiply both numbers' frequencies.
Why multiply? -1,1,1,1...-1 can form pair with all the three 1's.

handing 0's : 2 zeroes can form pair equal to zero sum. 
to calculate pairs of zeroes => (map[0]*(map[0]-1)/2 

0,0,0,0 -> can form 4 pairs=>[ n*(n-1)]/2

TC: O(n)
SC:O(n)
*/

 #include<bits/stdc++.h>
using namespace std;

int ZeroPairSum(vector<int> arr){
    map<int,int> store;
    for(auto i:arr)
    {
        store[i]++;
    }
    int res =0;
    for(auto i:store)
    {
        if(store.find(-(i.first))!=store.end() and i.first != 0)
        {
            int m = store[i.first]*store[-(i.first)];
            res+=m;
            store.erase(-(i.first));
        }
        else if(i.first == 0 and store[0]>1)
        {
            res+=(store[0]*(store[0]-1))/2;
        }
    }
    
    return res;
}
