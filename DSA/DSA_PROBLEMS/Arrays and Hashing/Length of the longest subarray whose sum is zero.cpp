/*

Length of the longest subarray whose sum is zero

*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        map<int,vector<int>> cache;
        int sum=0;
        int max_len=0;
        cache[0].push_back(-1);
        for(int i=0;i<A.size();++i)
        {
            sum+=A[i];
            
            if(cache.count(sum))
            {
                int least = cache[sum][0];
                int len = i-least;
                max_len = max(max_len,len);
            }
            else
            cache[sum].push_back(i);
        }
        
        return max_len;
    }
};

