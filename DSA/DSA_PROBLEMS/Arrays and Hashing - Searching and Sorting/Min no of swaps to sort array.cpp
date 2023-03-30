
/*
Minimum number of swaps required to sort an array

Intuition : Counting swaps for converting given array to sorted order is same as converting sorted form of given array to given form.
Before sorting, note the indices of elements in originally given array.
Reverse approach

https://www.youtube.com/watch?v=-2_c4lG7k_M&ab_channel=CppNuts
TC:O(N)
*/


#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> temp;
int min_swaps_sort(vector<int>& nums)
{
    int swaps = 0;
    for(int i=0;i<nums.size();++i)
    {
        temp.push_back({nums[i],i});
    }
    sort(temp.begin(),temp.end());
    
    for(int i=0;i<nums.size();++i)
    {
        if(temp[i].second==i) continue;
        else{
            swaps++;
            swap(temp[i],temp[temp[i].second]);
            --i;
        }
    }
    
    return swaps;
    
}
int main()
{
    vector<int> input = {101, 758, 315, 730,
           472, 619, 460, 479};
    cout<<min_swaps_sort(input);

    return 0;
}
