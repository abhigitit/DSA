/*
Pairs of Songs With Total Durations Divisible by 60

O(N^2) easy implementation.
(x+y)%N = 0 means x%N = R1, y%N=R2
R1+R2 = 0 or N

R1<N and R2<N
0<=R1+R2<=2N
The two numbers that are divisible by N in this range are 0 and N


Compute %N for each value and store it in an array. Does this become a 2 Sum problem? Where target = N(60). Cannot be 0 because everything is positive.

Use map to store remainder : frequency
And if the remainder is 0 or 30, we are looking for another 0 or 30 respectively. 

*/

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int,long long> mp;
        long long res = 0;
        for(int i=0;i<time.size();++i)
        {
            time[i] = time[i]%60;
        }

        for(auto i:time)
        {
            mp[i]++;
        }
         for(auto i:time)
        {
           if(mp.count(60-i))
           {
               if(i!=0 and i!=30)
               {
                    res+= mp[i]*mp[60-i];
                        mp.erase(i);
               }
           }
        }
        res+=mp[0]*(mp[0]-1)/2;
        res+= mp[30]*(mp[30]-1)/2;
      
        return res;

    }
};
