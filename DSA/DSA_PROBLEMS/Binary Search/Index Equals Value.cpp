/*
Index Equals Value
Sorted array of distinct elements. Return the first index in the array that equals the value.
AE
Intution : Binary Search
*/

#include <bits/stdc++.h>
using namespace std;


int helper(int left, int right,vector<int> array)
{
  if(left<=right)
  {
    int middleidx = (left+right)/2;
    int middlevalue = array[middleidx];

    if(middlevalue<middleidx)
      return helper(middleidx+1,right,array);
    else if(middlevalue==middleidx and middleidx==0)
      return middleidx;

    else if(middlevalue==middleidx and array[middleidx-1]<middleidx-1)

      return middleidx;

else
  return helper(left,middleidx-1,array);
}
else
return -1;

  
  
}
int indexEqualsValue(vector<int> array) {
  return helper(0,array.size()-1,array);
 
}
