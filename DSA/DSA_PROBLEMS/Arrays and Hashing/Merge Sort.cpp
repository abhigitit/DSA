/*
Merge Sort
*/

#include <bits/stdc++.h>
using namespace std;
vector<int> res;

void mergeSort_helper2(int left, int mid, int right)
{
  int left_size = mid+1-left;
  int right_size = right-mid;
  vector<int>left_arr(left_size,0);
  vector<int>right_arr(right_size,0);
  for(int i=0;i<left_size;++i)
    {
      left_arr[i]=res[left+i];
    }
  for(int i=0;i<right_size;++i)
    {
      right_arr[i]=res[mid+1+i];
    }

  int k = left;
  int l=0,r=0;
  while(l<left_size and r<right_size)
  {
  if(left_arr[l]<right_arr[r])
  res[k++]=left_arr[l++];
  else
  res[k++]=right_arr[r++];
  }

while(l<left_size)
  {
    res[k++]=left_arr[l++];
  }
while(r<right_size)
  {
    res[k++]=right_arr[r++];
  }
}
void mergeSort_helper1(int left, int right)
{
  if(left<right)
  {
    int mid = (left +right)/2;
    mergeSort_helper1(left,mid);
    mergeSort_helper1(mid+1,right);
    mergeSort_helper2(left,mid,right);
  }
}
vector<int> mergeSort(vector<int> array) {
  res = array;
  mergeSort_helper1(0,array.size()-1);
  return res;
}
