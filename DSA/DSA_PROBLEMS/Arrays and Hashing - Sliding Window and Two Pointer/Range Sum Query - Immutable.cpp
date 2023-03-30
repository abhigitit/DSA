/*
Range Sum Query - Immutable

1D array => should be able to return sum between specific indices in constant time.
To do that we need to compute sums of all subarrays and keep it handy.

Are we going to calculate the sum of all subarrays in O(n^2). NO

Prefix Sum:
The sum until that index. 


L and R are range indices. 
Now R has sum till R from 0. Now L-1 has sum from 0 to L-1. 
No our answer between L and R is (prefix sum till R - prefix sum till L-1)

*/
class NumArray {
public:
vector<int> nums;
    NumArray(vector<int>& nums) {
        this->nums = nums;
        prefixsum();
    }
    void prefixsum()
    {
        int running_sum = 0;
        for(int i=0;i<nums.size();++i)
        {
            running_sum+=nums[i];
            nums[i] = running_sum;
        }
    }
    int sumRange(int left, int right) {
        return left!=0 ? (nums[right]-nums[left-1]) : nums[right];
    }
};
