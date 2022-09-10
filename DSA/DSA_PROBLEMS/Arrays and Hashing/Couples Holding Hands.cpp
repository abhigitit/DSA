
/*

Leetcode: 765

Intuition : If the number we are currently on is even number, then the next number which is the partner is number+1. Else number -1. This is because couples
start from 0,1. 2,3 4,5 ....

We use map and store indices and if there is no couple beside we swap and update indices again.
This is greedy approach.

TC:O(N)

*/

class Solution {
public:
    unordered_map<int,int> store;
    int minSwapsCouples(vector<int>& row) {
       
        
        int res =0;
        for(int i=0;i<row.size();++i)
        {
            store[row[i]] = i;
        }
        
        for(int i=0;i<row.size();i+=2)
        {
            int first = row[i];
            int second = first^1;
            if(row[i+1] != second)
            {
                swap_func(row,i+1,store[second]);   
                   res++; 
            }
                
        }
        return res;
    }
    
    void swap_func(vector<int>& row,int i,int j)
    {
        int temp = row[j];
        row[j] = row[i];
        row[i] = row[j];
        store[row[i]] = i;
        store[row[j]] = j;
    }
};
