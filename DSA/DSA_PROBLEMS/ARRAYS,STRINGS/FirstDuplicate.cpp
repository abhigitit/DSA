
/*First Duplicate*/

/*Find the first duplicate element in the given array*/

/*Algorithm
Loop throught the array, push elements to the set and simultaneously check if the element is present in the set. Return the elements if its already present
*/

/* TC = O(n)
SC = O(n)
*/

#include <bits/stdc++.h>
#include<vector>
#include<set>
using namespace std;
 int firstDuplicate(vector<int> s) {
       set<int> store;
        for(int i:s){
            if(store.find(i)!=store.end())
            return i;
            else{
                store.insert(i);
            }
        }
return -1;
    }
int main(){
   vector<int> x={1,1,2,2,3,4,5};
    int y = firstDuplicate(x);
    cout<<y;
}
