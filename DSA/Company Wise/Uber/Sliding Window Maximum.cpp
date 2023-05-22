class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      vector<int> res;
      deque<int> d;
        int left = 0;
      for(int i=0;i<nums.size();++i) {

          while(d.size() and nums[i]>nums[d.back()])
          {
              d.pop_back();
          }
          d.push_back(i);

         if(left>d.front())
         {
            d.pop_front();
         }
        if(i+1>=k)
        {
            res.push_back(nums[d.front()]);
            left++;
        }

      }

      return res;

        
    }
};
