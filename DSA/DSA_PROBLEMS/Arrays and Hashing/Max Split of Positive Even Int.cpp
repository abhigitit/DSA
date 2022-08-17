/*
Leetcode: 2178

Intuition: If the number is odd return empty list.
Keep on adding positive even integers from 2 to the list until the total sum < final sum.
When the loop ends, the total sum will be greater than or equal to final sum. If its equal, return the list else,
Find the value that is excess=> (total sum - final sum) and remove it from the list.

*/
class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if((finalSum%2)!=0) return {};
      vector<long long> res;
        long long sum = 2;
        long long total = 0;
        while(total<finalSum)
        {
            total+=sum;
            res.push_back(sum);
            sum+=2;
        }
        if(total==finalSum)
        return res;
        else
        {
            int j=0;
            for(int i=0;i<res.size();++i)
            {
                if(res[i]==total-finalSum)
                    j=i;
            }
            res.erase(res.begin()+j);
        }
        
        return res;
    }
};
