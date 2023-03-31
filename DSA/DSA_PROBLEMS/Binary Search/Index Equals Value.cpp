/*
Index Equals Value
Sorted array of distinct elements. Return the first index in the array that equals the value.
AE
Intution : Binary Search
*/

#include <vector>
using namespace std;

int indexEqualsValue(vector<int> array) {
  int left = 0;
  int right = array.size()-1;

  while(left<=right)
    {
      int middleidx = left + (right-left)/2;

      if(array[middleidx]<middleidx)
        left = middleidx + 1;

      else if(array[middleidx]==middleidx and middleidx==0)
        return middleidx;

      else if(array[middleidx]==middleidx and array[middleidx-1]<middleidx-1)
        return middleidx;

      else
          right = middleidx - 1;
    }
  return -1;
}
