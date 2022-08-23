/*
Leetcode Unique Paths

Brute force TC : O(2 ^ (n+m))
Memoized TC:O(n*m)

*/

class Solution {
public:
    map<string,int> memoize;
    int uniquePaths(int m, int n) {
        
        string key = to_string(m) + ',' + to_string(n);
        if(memoize.find(key)!=memoize.end())
            return memoize[key];
        if(m==1 or n==1) return 1;
        if(m==0 or n==0) return 0;
        memoize[key]=uniquePaths(m-1,n) + uniquePaths(m,n-1);
        return memoize[key];
    }
};
