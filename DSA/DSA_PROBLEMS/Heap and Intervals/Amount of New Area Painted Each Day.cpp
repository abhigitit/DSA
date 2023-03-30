
/*
Amount of New Area Painted Each Day
leetcode: 2158

https://www.youtube.com/watch?v=cHYjuMPTHt4&ab_channel=CrackingFAANG
TC:O(N^2)
*/


class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
      unordered_map<int,int> cache;
        vector<int> res;
        for(int i=0;i<paint.size();++i)
        {
            int start = paint[i][0];
            int end = paint[i][1];
            int work=0;
            while(start<end)
            {
                if(cache.find(start)!=cache.end())
                {
                    int prev_end = cache[start];
                    cache[start] = max(cache[start],end);
                    start = prev_end;
                }
                else
                {
                  cache[start]= end;
                    start++;
                    work++;
                }
            }
            
            res.push_back(work);
        }
        return res;
    }
};

__
    codesignal chunks question
    
 
#include <bits/stdc++.h>

using namespace std;

vector<long long> solution(vector<vector<long long>> chunks) {
map<long long,long long> cache;
vector<long long> res;
long long temp = 0;
for(long long i=0;i<chunks.size();++i)
{
    long long start = chunks[i][0];
    long long end = chunks[i][1];
    long long work = 0;
    
    while(start<=end)
    {
        if(cache.count(start))
        {
            long long prev = cache[start];
            cache[start] = max(prev,end);
            start = prev+1;
        }
        else {
            cache[start] = end;
            start++;
            work++;
        }
        
    }
    temp+=work;
    res.push_back(temp);
}
return res;
}


int main()
{
    vector<vector<long long>> chunks = {{7,9},{1,3},{2,6},{10,15}};
    
   vector<long long> res = solution(chunks);
   for(auto i:res)
   {
       cout<<i<<endl;
   }

    return 0;
}

