/*
Arranging Coins 441

https://www.youtube.com/watch?v=5rHz_6s2Buw&ab_channel=NeetCode

Brute force: Given 10 coins -> first row 1 coin, second row 2, until we max out 10 coins. O(N) sol

Binary Search : We can add all the numbers from 1 to n in sequential manner O(N).
But we have Guass's formula of adding numbers from 1 to n which is n(n+1)/2 in O(1) time;
There are exactly n/2 pairs of numbers which equal to value n+1.

Example: 1,2,3,4........100
n+1 = 100 + 1 = 101
How may pairs make 101 => 1+100, 2+99...50+51
Hence the formula n(n+1)/2

Minimum number of rows will be 1 (atleast 1 coin is give in the problem)
Max number of rows will be n (will be logically less than n but can be used as upper bound)

There are 5 coins give.
Lb = 1
Ub = 5
Mid = 3
Check if we can atleast complete 3 rows with the given coins.

Constant time intuition : No of complete rows be R..then R(R+1)/2 = n..R will be 2. something for 5 coins which will be rounded to 2.
*/

class Solution {
public:
    int arrangeCoins(int n) {
        long l=1;
        long r=n;
        long res=0;
        while(l<=r)
        {
            long mid = l + (r-l)/2;
            long coins = mid*(mid+1)/2;
           if(coins==n) // if the total coins required to build mid number of rows, equals given coins return this
               return mid;
            else if(coins>n) // if the total coins required to build mid number of rows is greater than given, we cant build this and all to right.
                r=mid-1;
            else
                l=mid+1; //if we can build this with lesser coins, there exists answer on the right which is higher number of rows
        }
        return r;
    }
};

