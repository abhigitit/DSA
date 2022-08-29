
/*
Longest Increasing consecutive subsequence
*/


#include<bits/stdc++.h>
using namespace std;

int LICS(vector<int> &input)
{
    int max_lics = 0;
    int curr =1;
    for(int i=1;i<input.size()-1;++i)
    {
        if(input[i]>input[i-1])
        curr++;
        else
        curr=1;
        max_lics = max(max_lics,curr);
    }
    return max_lics;
}

int main()
{
   vector<int> input = {1,2,4,99,5,6,7,-1};
   cout<<LICS(input);
  
}
