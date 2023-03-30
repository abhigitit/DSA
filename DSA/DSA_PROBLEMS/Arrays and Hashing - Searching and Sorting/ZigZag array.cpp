/*
ZigZag Array : Given an array arr of distinct elements of size N, the task is to rearrange the elements of the array in a zig-zag fashion so that the converted array should be in the below form: 

arr[0] < arr[1]  > arr[2] < arr[3] > arr[4] < . . . . arr[n-2] < arr[n-1] > arr[n]. 

Intuition 1: Sort the array and keep the first element as it is. Swap 1,2..3,4..5,6 O(nlogn)

Intuition 2: Use flag. flag = 0 handles "if the current element needs to be lesser than next" and flag =1 handles other case

TC:O(N)
SC:O(1)

*/

class Solution{
public:	
	void zigZag(int temp[], int n) {
	    bool flag = 0;
	   for(int i=0;i<n-1;i++)
	   {
	      if(!flag and temp[i]>temp[i+1]) 
	      {
	          swap(temp[i],temp[i+1]);
	      }
	      else if(flag and temp[i]<temp[i+1])
	      {
	          swap(temp[i],temp[i+1]);
	      }
	      flag=!flag;
	   }
	}
};
