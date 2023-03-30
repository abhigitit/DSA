/*
Quick Sort

https://www.youtube.com/watch?v=7h1s2SojIRw&ab_channel=AbdulBari
*/

#include <vector>
using namespace std;


int partition(int left,int right,vector<int>& array)
{
  int pivot = array[left];
  int i=left;
  int j=right;
  while(i<j)
    {
      while(array[i]<=pivot) i++;
      while(array[j]>pivot) j--;
      if(i<j)
        swap(array[i],array[j]);
    }
  swap(array[left],array[j]);
  return j;
}
void quicksort_helper(int left,int right,vector<int>& array)
{
  if(left<right)
  {
    int j = partition(left,right,array);
    quicksort_helper(left,j-1,array);
    quicksort_helper(j+1,right,array);
  }
}
vector<int> quickSort(vector<int> array) {
  quicksort_helper(0,array.size()-1,array);
  return array;
}
