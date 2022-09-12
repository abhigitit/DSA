/*
Leetcode: 1221

Intuition : Increment, decrement counter

https://www.youtube.com/watch?v=rnwmE9m9EMM&ab_channel=KevinNaughtonJr.

*/

class Solution {
public:
    int balancedStringSplit(string s) {
       int count =0;
        int res =0;
        
        for(auto i:s)
        {
            if(i=='R') count--;
            else if(i=='L') count++;
            
            if(count==0) res++;
        }
        
        return res;
    }
};
