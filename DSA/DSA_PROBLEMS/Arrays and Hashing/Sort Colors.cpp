/*
Sort Colors(75)
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left =0,mid=0;
        int right = nums.size()-1;
        
     while(mid<=right)
     {
         int num = nums[mid];
            switch(num)
            {
                case 0:
                    swap(nums[left++],nums[mid++]);
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[right--],nums[mid]);
                    break;
            }
     }      
        
    }
};
