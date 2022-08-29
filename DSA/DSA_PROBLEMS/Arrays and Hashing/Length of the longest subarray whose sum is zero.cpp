/*

Length of the longest subarray whose sum is zero

*/

#include <bits/stdc++.h>

using namespace std;



int len_LSAWS_zero(vector<int> input)
{
    int sum =0;
    int max_len = 0;
    unordered_map<int,vector<int>> store;
    for(int i=0;i<input.size();++i)
    {

        sum+=input[i];
         if (input[i] == 0 && max_len == 0)
            max_len = 1;
        
        if(store.find(sum)!=store.end())
        {
            int j = store[sum][0];
            int len = i-j;
            max_len = max(max_len,len);
        }
        store[sum].push_back(i);
       
        
    }
    return max_len;
}
int main()
{
    vector<int> input = { 15, -2, 2, -8, 1, 7, 10, 23 };
    cout<<len_LSAWS_zero(input);

    return 0;
}
