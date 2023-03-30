
/*
  COUNT INVERSIONS in an ARRAY; count all pairs where a[i]>a[j] and j>i
  */

#include <bits/stdc++.h>
using namespace std;
vector<int> res;

int mergeSort_helper2(int left, int mid, int right)
{

    int left_size = mid+1-left;
    int right_size = right-mid;
    int inv_count = 0; 
    vector<int> left_arr(left_size,0);
    vector<int> right_arr(right_size,0);
    
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
        {
            res[k++]=left_arr[l++];
        }
        else
        {
            inv_count += mid-l+1;
            res[k++]=right_arr[r++];
        }
    }
    
    while(l<left_size)
    {
        res[k++]=left_arr[l++];
    }
    
     while(r<right_size)
    {
        res[k++]=right_arr[r++];
    }
    return inv_count;
}
int mergeSort_helper1(int left, int right)
{
    int inv_count = 0; 
    if(left<right)
    {
        int mid = left+(right-left)/2;
        inv_count+=mergeSort_helper1(left,mid);
        inv_count+=mergeSort_helper1(mid+1,right);
        inv_count+=mergeSort_helper2(left,mid,right);
    }
    return inv_count;

}
int mergeSort(vector<int> array) {
 res = array;
  int inv = mergeSort_helper1(0,array.size()-1);
  return inv;
}

int main()
{
    vector<int> arr = { 20, 6, 4, 5 , 44};
   int res = mergeSort(arr);
    cout<<res<<endl;

    return 0;
}
