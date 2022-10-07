/*

Capacity To Ship Packages Within D Days

Intuition : Maximum wt that the ship can have is when the days given is 1 and all the prodcuts need to be shipped which is sum of all product's weights.
Minimum wt the ship can have is when the number of days given equals number of products, then product with max wt becomes the minimum wt the ship should have.

Find low, high. THe minimum wt the ship can have is in this range low<=ans<=high

Can perform bruteforce and improve the solution with binary search.
If mid value of that range is not the answer, first half can be eliminated.

TC: O(NlogN)

*/

Brute Force:
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        
        int high = 0;
        int low = *max_element(weights.begin(),weights.end());
        for(auto i:weights)
        {
            high+=i;
        }
        for(int i=low;i<=high;++i)
        {
            
            int temp_days = 0;
            int k=0;
            while(k<weights.size())
            {
                int total_wt = 0;
                  while(k<weights.size() and total_wt + weights[k]<=i)
                    {
                        total_wt+=weights[k++];
                    }
                temp_days++;
            }
         cout<<temp_days<<endl;
            if(temp_days<=days) return i;
           
        }
        
        return -1;
    }
};

Binary Search:

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        
        int high = 0;
        int low = *max_element(weights.begin(),weights.end());
        for(auto i:weights)
        {
            high+=i;
        }
       
            
          while(low<high)
          {
              int mid = (low+high)/2;
              if(isshipped(mid,weights,days))
                  high = mid;
              else
                  low = mid+1;
          }
           
        
        
        return high;
    }
    
    bool isshipped(int i,vector<int>& weights,int days)
    {
          int temp_days = 0;
            int k=0;
            while(k<weights.size())
            {
                int total_wt = 0;
                  while(k<weights.size() and total_wt + weights[k]<=i)
                    {
                        total_wt+=weights[k++];
                    }
                temp_days++;
            }
        
            return temp_days<=days;
    }
};
