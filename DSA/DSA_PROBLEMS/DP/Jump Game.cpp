/*
Leetcode: Jump Game
Intuition : 
Move the goal post from the last index to the first index and this means that the last index is reachable from the first index.

When to move the goal post?
Only when the prev value + index >= goal post index

*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
       int goal = nums.size()-1;
        for(int i=nums.size()-2;i>=0;--i)
        {
            if(nums[i]+i>=goal)
                goal=i;
        }
        return goal==0;
    }
};
