/* Subsequence of another array */

/*
Input: array = [1,2,3,4,5,6,9]
Sequence : [4,5,9] // aren't necessarily adjacent but in sequence
output: true
*/

/*Algorithm
Loop through the big array and if the sequence array’s element is present in the big array, 
increment seqindex and break when seqindex reaches the sequence array’s size. 
If it has reached sequence array's size, that implies all the elements are present in the array.
*/

/* Time Complexity = O(n)
Space Complexity = 0(1)
*/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
int seq_index=0;
	for(int i:array){
		if(sequence[seq_index]==i)
			seq_index++;
		if(seq_index == sequence.size())
			break;
	}
  return seq_index==sequence.size();
}

int main(){
   vector<int> array{1,2,5,-7,9,0,99,102};
   vector<int> sequence{2,0,102};
   cout<<isValidSubsequence(array,sequence);
    return 0;
}
