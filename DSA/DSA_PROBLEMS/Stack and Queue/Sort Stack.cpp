/*
Sort Stack In place
 
 O(n^2)
 
 remove all elements using recursive calls and each call has its top element stored. (see img google dsa)
 then use another recursive function insert to handling insertions.
 
 */

#include <vector>
using namespace std;
void insert(int insert_element, vector<int> &stack)
{
  
  if(stack.size()==0 or insert_element>=stack.back())
    {
      stack.push_back(insert_element);
      return;
    }
   int top = stack.back();
    stack.pop_back();
    insert(insert_element,stack);
   stack.push_back(top);
  
}
void sort(vector<int> &stack)
{
  if(stack.size()==0)
    return;
  int top_element = stack.back();
  stack.pop_back();
  sort(stack);
  insert(top_element,stack);
}

vector<int> sortStack(vector<int> &stack) {
  sort(stack);
  return stack;
}
