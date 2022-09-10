
/*
AE
Two arrays representing two BSTs are given. If BST is constructed from the arrays in the given order of elements, and if the BSTs are the same, return true

Intuiton : If arrays sizes differ, return false.
If both arrays sizes are 0, return true.
if first element differs, return false.

Build two arrays for each given array. One array with all the elements less than the first element. One array with all the elements 
greater than the first element.

Repeast the process recursively.

*/




#include <vector>

using namespace std;

bool sameBsts(vector<int> arrayOne, vector<int> arrayTwo) {
 if(arrayOne.size()!=arrayTwo.size()) return false;
  if(arrayOne.size()==0 and arrayTwo.size()==0) return true;
  if(arrayOne[0]!=arrayTwo[0]) return false;

  vector<int> bst11;
  vector<int> bst12;
  vector<int> bst21;
  vector<int> bst22;

  for(int i=1;i<arrayOne.size();++i)
    {
      if(arrayOne[i]<arrayOne[0])
        bst11.push_back(arrayOne[i]);
      else
        bst12.push_back(arrayOne[i]);
    }

  for(int i=1;i<arrayTwo.size();++i)
    {
      if(arrayTwo[i]<arrayTwo[0])
        bst21.push_back(arrayTwo[i]);
      else
        bst22.push_back(arrayTwo[i]);
    }
  return sameBsts(bst11,bst21) and sameBsts(bst12,bst22);
}
