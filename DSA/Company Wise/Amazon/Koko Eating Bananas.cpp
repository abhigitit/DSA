/*
Koko Eating Bananas

Minimum = 1
Maximum = max element in the array if the no of hours equals array size.

Binary Search
Similar to capacity to ship packages problems 

*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long left = 1;
        long right = *max_element(piles.begin(),piles.end());
        
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            if(canEat(mid,piles,h))
                right = mid-1;
            else
                left = mid+1;
        }
        return left;
       
      
    }
    
    bool canEat(int mid,vector<int>& piles, int h)
    {
        
            long temp_hours=0;
          
               for(auto j:piles)
               {
                  temp_hours+= j%mid==0 ? j/mid : j/mid + 1; 
               }
               
           
            return temp_hours<=h;
   
    }
};
