/*
  Happy Number
  Use set to store sums and break the loop when n is not becoming 1.
  */

class Solution {
public:
    bool isHappy(int n) {
      set<int> seen;
       while(n!=1)
       {
           int current = n;
           int sum=0;
           while(current)
           {
               sum+= pow(current%10,2);
               current = current/10;
           }
           
           if(seen.count(sum))
               return false;
           else
               seen.insert(sum);
           n=sum;
       }
        return true;
    }
};
