/*
Leetcode : 442. Find All Duplicates in an Array
Intuiton : Number - 1 is always an index in the array.
*/



    vector<int> findDuplicates(vector<int>& nums) {
       vector<int> res;
        
        for(int i=0;i<nums.size();++i)
        {
            int new_index = abs(nums[i])-1;
            if(nums[new_index]>0)
                nums[new_index]=-nums[new_index];
            else
                res.push_back(abs(nums[i]));
        }
        return res;
    }
};
