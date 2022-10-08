/*

Median of Two Sorted Arrays

Intuition: https://www.youtube.com/watch?v=LPFhl65R7ww&t=1223s&ab_channel=TusharRoy-CodingMadeSimple

*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       
        if(nums1.size()>nums2.size())
            return findMedianSortedArrays(nums2,nums1);
        
        int x = nums1.size();
        int y = nums2.size();
        int low = 0;
        int high = x;
        
        while(low<=high)
        {
            int partX = (low+high)/2;
            int partY = (x+y+1)/2 - partX;
            
            int maxleftX = partX==0 ? INT_MIN : nums1[partX-1];
            int minrightX = partX==x ? INT_MAX : nums1[partX];
            
            int maxleftY = partY==0 ? INT_MIN : nums2[partY-1];
            int minrightY = partY==y ? INT_MAX : nums2[partY];
           
            
            if(maxleftX<=minrightY and maxleftY<=minrightX)
            {
                if((x+y)%2==0)
                    return double((max(maxleftX,maxleftY) + min(minrightX,minrightY)))/2;
                else
                    return double(max(maxleftX,maxleftY));
            }
            else if(maxleftX>minrightY)
                high = partX-1;
            else
                low = partX+1;
        }
        
        return 0.0;
    }
};
