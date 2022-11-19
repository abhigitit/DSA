/*
Sum of Subarray Ranges

Brute force : Nestsed Loops

Intuition: To find the next/prev immediate greater or lesser, we use monotonic stacks. Consider every element to be min and max of its subarrays. 
To find the subarrays the curr element is min in, use increasing monotonic stack where we get the elements which are lesser than currently considered(min)
on its both sides and we use the formula of "num of subarrays = (curr_idx-left_idx)*(right_idx*curr_idx)" and multiply it with the number.

If my current number should be the minimum in the subarray, set boundaries => what is the smallest number than my current number to left and right.

Use monotonic dec stack to find prev greater and next greater
Whatever number is directly underneath the current number is the prev greater => 10,8,7 = > inside mon dec stack 10,8,7.. for 8 prev greater is 10.
Next greater element is when we pop.


Use monotonic inc stack to find prec smallest and next smallest
Whatever number is directly underneath the current number is the prev lesser 

https://www.youtube.com/watch?v=yAoN-EQRszk&ab_channel=KacyCodes


*/

----
O(N) Monotonic Stacks

class Solution {
public:
    stack<int> dec_stack;
    stack<int> inc_stack;
    long long subArrayRanges(vector<int>& nums) {
        
        long long sum=0;
        
        for(int i=0;i<=nums.size();++i)
        {
            sum+= whatIfMax(i,nums) - whatIfMin(i,nums);
        }
        
        return sum;
    }
    
    long long whatIfMax(int i, vector<int>& nums)
    {
        long long sum=0;
        while(!dec_stack.empty() and (i==nums.size() or nums[i]>nums[dec_stack.top()]))
        {
            int curr_i = dec_stack.top();
            dec_stack.pop();
            int prev_i = dec_stack.empty() ? -1 : dec_stack.top();
            sum += (i-curr_i)*(curr_i-prev_i)*(long long)(nums[curr_i]);
        }
        
        dec_stack.push(i);
        return sum;
    }
    
      long long whatIfMin(int i, vector<int>& nums)
    {
        long long sum=0;
        while(!inc_stack.empty() and (i==nums.size() or nums[i]<nums[inc_stack.top()]))
        {
            int curr_i = inc_stack.top();
            inc_stack.pop();
            int prev_i = inc_stack.empty() ? -1 : inc_stack.top();
            sum += (i-curr_i)*(curr_i-prev_i)*(long long)(nums[curr_i]);
        }
        
        inc_stack.push(i);
        return sum;
    }
};

__
    
    Brute Force
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        
        long long sum=0;
        for(int i=0;i<nums.size();++i)
        {
            int mini=nums[i];
            int maxi=nums[i];
            for(int j=i+1;j<nums.size();++j)
            {
              mini= min(mini,nums[j]);
              maxi = max(maxi,nums[j]);
              sum+= (maxi-mini);
            }
        }
        
        return sum;
    }
};
