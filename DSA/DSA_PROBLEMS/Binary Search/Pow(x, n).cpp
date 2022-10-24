/*
Pow(x, n)

Intuition : 2^10 => 2*2*2.....10 times
We can do 2^5 and then multiply with itself
We can break the problem into subparts and solve. Divide and Conquer

Negative power is handled after calculating the res
O(logN)

*/

class Solution {
public:
    double res;
    double myPow(double x, int n) {
        res = helper(x,abs(n));
        return n>0 ? res : 1/res;
    }
    
    double helper(double x, int n)
    {
        if(x==0)
            return 0;
        if(n==0)
            return 1;
        
        res = helper(x,n/2);
        res= res*res;
        return n%2==0 ? res : x*res;
    }
};
