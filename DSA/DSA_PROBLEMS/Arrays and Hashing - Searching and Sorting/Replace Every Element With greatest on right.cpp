/*

Replace every element with greatest element on the right side

Intuition : Loop from backside and keep track of max element and update accordingly

*/

#include <bits/stdc++.h>
using namespace std;
  
  
  
void replace(vector<int>& nums)
{
    
 int max_e = nums[nums.size()-1];
nums[nums.size()-1] = -1;
 for(int i=nums.size()-2;i>=0;i--)
 {
     int temp = nums[i];
     nums[i] = max_e;
     max_e = max(max_e,temp);
 }
 
}

int main()
{
   
 vector<int> input = {2,4,5,6,4,5,1};
 replace(input);
for(auto i: input)
{
    cout<< i << ",";
}
  return 0;
}
