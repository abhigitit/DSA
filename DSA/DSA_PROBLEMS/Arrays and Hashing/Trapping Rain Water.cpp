
/*
leetcode : 42
https://www.youtube.com/watch?v=ZI2z5pq0TqA&t=58s&ab_channel=NeetCode

Intuition : Water that can be trapped at current position = min(max left boundary height, max right boundary height) - height[current poitison]
min(max left boundary height, max right boundary height) logic is same as the logic that comes from maximum water container and height[current poitison] should be 
subtracted to calculate the correct quantity of water.

To calculate the quantity of water that can be trapped at a position, we need to know the max left boundary height and max right right boundary height for each position.

Calcuate max left height and max right height at each position and store in two arrays.

Use the formula min(max left boundary height, max right boundary height) - height[current poitison] in single iteration to calculate result.

TC: O(N)
SC : O(N)

*/

class Solution {
public:
    int trap(vector<int>& height) {
       int res = 0;
    vector<int> max_left(height.size());
     vector<int> max_right(height.size()); 
        int max_left_value = 0;
        int max_right_value = 0;
        for(int i=1;i<height.size();++i)
        {
           max_left_value =max(max_left_value,height[i-1]);
            max_left[i] = max_left_value;
        }
        
        for(int i=height.size()-2;i>=0;--i)
        {
            max_right_value=max(max_right_value,height[i+1]);
            max_right[i] = max_right_value;
        }
        
        for(int i=0;i<height.size();++i)
        {
            int temp = min(max_left[i],max_right[i]) - height[i];
            if(temp>=0)
            res+=temp;
        }
        return res;
    }
};
