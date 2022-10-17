/*
Ugly Number II

Brute Force : Loop through all numbers until n and check if they are ugly. Return nth ugly number.

Intuition : Merge 3 sorted lists
list1 => Multiples of 2 => 2,4,6,8,10,12,14...
list2 => Multiples of 3 => 3,6,9,12,15,18...
list3 => Multiples of 5 => 5,10,15,20,25...

These are the possible ugly numbers. Find nth ugly number by merging them into a list of size n.

https://www.youtube.com/watch?v=uLctkg4Yf8M&ab_channel=SaiAnishMalla

*/

class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[n+1]; // initialize dp array with n+1
        dp[1] =1;
        int p2 =1, p3 = 1, p5 = 1;// pointer p2 is for 2, p3 for 3, p5 for 5
        for(int i =2; i<= n ; i++){
            int f2 =  2* dp[p2]; 
            int f3 = 3* dp[p3];
            int f5 = 5* dp[p5];
            int min_ = min({f5, f2, f3}); // find the min  of all 
			//suppose p2, p3 & p5 are at dp[0]  f2 will be  2* 1 , 3*1 , 5*1 
            dp[i] = min_; // store the next dp[1] to the minimum of all (f2, f3, f5)
			//after storing the minimum 
            if(min_ == f2) p2++; // increment if f2 is min
            if(min_ == f3) p3++;// increment if f3 is min
            if(min_ == f5) p5++;// increment if f5 is min
         }
        return dp[n]; // return dp of n
    }
};
