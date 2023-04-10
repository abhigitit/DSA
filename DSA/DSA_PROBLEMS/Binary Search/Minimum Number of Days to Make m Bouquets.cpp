/*
Minimum Number of Days to Make m Bouquets

https://www.youtube.com/watch?v=oYE6wuYhqZE&t=1802s
*/

class Solution {

    bool helper(int days,vector<int>& bloomDay, int m, int k)
    {
        int adj=0,boq=0;
        for(int i=0;i<bloomDay.size();++i)
        {
            if(bloomDay[i]<=days)
            {
                adj++;
                if(adj==k)
                {
                    boq++;
                    if(boq==m)
                        return true;
                    adj=0;
                }

            }
            else
            {
                adj=0;
            }
        }
        return false;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int res = INT_MAX;
        if(m/2*k> bloomDay.size()/2)
            return -1;
    while(low<=high)
    {
    int mid = low + (high-low)/2;
    if(helper(mid,bloomDay,m,k))
    {
        res = min(res,mid);
        high = mid-1;
    }
    else
	    low = mid+1;
    }
    return res!=INT_MAX ? res : -1;

    }
};
