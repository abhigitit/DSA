/*
SubArray Sum zero
Intuition : 
https://www.youtube.com/watch?v=8inhayLCCHs&ab_channel=HelloWorld
*/
#include <bits/stdc++.h>

using namespace std;
#define loop(n) for(int i=0;i<n;++i)

bool subArraySumZero(vector<int> input)
{
    unordered_set<int> seen;
    int n=input.size();
    int sum=0;
    loop(n)
    {
        sum+=input[i];
        if(sum==0) return true;
        if(seen.count(sum))
        return true;
        else
        seen.insert(sum);
    }
    return false;
}


int main()
{
    vector<int> input = {1,2,4,-8,3,9};
    cout<<subArraySumZero(input);

    return 0;
}
