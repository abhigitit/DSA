/* Max Sum SubArray 

 Write a function that takes in non empty array and returns max sum of subarray. Elements of subarray have to be adjacent

 INPUT = [1,2,3,-9,4,6,0,7,-1]
 max sum of subarray is 4+6+0+7 =17 

Kadane's Algorithm:
  At every element, check if the (current element) is the highest or (max sum till then + current element) is the highest.
  
Time Complexity : O(N)
Sapce Complexity: O(1)

*/


#include <bits/stdc++.h>
#include <vector>

using namespace std;

int kadanesAlgorithm(vector<int>& array) {
	int maxEndingHere=array[0];
	int maxsoFar=array[0];
	for(int i=1;i<array.size();i++)
	{
		int num = array[i];
		maxEndingHere=max(num,maxEndingHere+num);
		maxsoFar=max(maxEndingHere,maxsoFar);
	}
	return maxsoFar;
}

int main(){
   vector<int> array{1,2,3,-9,4,6,0,7,-1};
   cout<<kadanesAlgorithm(array);
    return 0;
}

