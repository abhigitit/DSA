
/* TwoSum */

/* Input: [3,5,-4,8,11,1,-1,6]
targetSum = 10
Output:[-1,11]//this is returning elements
Output : [4,6] //this is returning indices
*/

/*Algoritm
Loop through the array and also keep inserting elements into an unordered set. 
Subtract elements from targetsum and store in another variable and find if the variable is present in the set.
*/

//1)Return Elements
#include <bits/stdc++.h>
#include<vector>
#include <unordered_set>
using namespace std;


vector<int> twoNumberSum(vector<int> array, int targetSum) {
 unordered_set<int> num;
	for(int i : array){
		int match = targetSum - i;
	if(num.find(match)!=num.end()){
		return vector<int>{match,i};
	}
	else{
		num.insert(i);
	}
	}
  return {};
}

int main(){
   vector<int> x={1,1,2,2,3,4,5};
    vector<int> y = twoNumberSum(x,4);
  for(auto i:y)
  {
      cout<<i<<"\n";
  }
}

//2)Return Indices
#include <bits/stdc++.h>
#include<vector>
#include <map>
using namespace std;


 vector<int> twoNumberSum(vector<int>& nums, int target) {
        map<int,int> store;
        for(int i=0;i<nums.size();i++){
            store[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            int second = target - nums[i];
            if(store.find(second)!=store.end() && second!=nums[i])
            {
                return vector<int>{i,store[second]};
            }
             if(store.find(second)!=store.end() && second==nums[i])
            {
                 if(store[second]!=i)
                return vector<int>{i,store[second]};
            }
        }
        return {};
    }


int main(){
   vector<int> x={1,1,2,2,3,4,5};
    vector<int> y = twoNumberSum(x,4);
  for(auto i:y)
  {
      cout<<i<<"\n";
  }
}

