/*
Given a sorted array of integers, nums, and a target, return the index of the target within nums. 
If it does not exist, return the index of where target should be inserted.
*/

#include <bits/stdc++.h>

using namespace std;


vector<int> input = {0,4,8,19,65};
int insert(int left, int right,int target)
{
   while(left<right)
   {
       int mid = (left+right)/2;
       if(input[mid]==target) return mid;
       else if(input[mid]<target)
       return insert(mid+1,right,target);
       else
       return insert(left,mid,target);
   }
     return left;
   }
 


int main()
{
   
    cout<<insert(0,input.size()-1,20);
    return 0;
}
