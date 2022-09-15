
/*
Given an array arr[], find the maximum j – i such that arr[j] > arr[i]


Intuition: COllect element with indices of each element into another array and then sort the array.
https://www.youtube.com/watch?v=yKITDmQm0D4&ab_channel=alGOds
*/

class Solution{
    public:

    int maxIndexDiff(int A[], int N) 
    { 
        vector<pair<int,int>> temp;
        
      for(int i=0;i<N;++i)
      {
          temp.push_back({A[i],i});
      }
      
      
      sort(temp.begin(),temp.end());
      
      int min_idx = INT_MAX;
      int max_diff = INT_MIN;
      
      for(int i=0;i<temp.size();++i)
      {
          min_idx = min(min_idx,temp[i].second);
          max_diff = max(max_diff,temp[i].second-min_idx);
      }
        return max_diff;
    }
};
