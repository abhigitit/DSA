/*
Product of Array Except Self
*/

#include <algorithm>
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> farray;
        vector<int> sarray;
        vector<int> result;
        int temp =1;
        farray.push_back(1);
        sarray.push_back(1);
        for(int i=1;i<nums.size();i++){
            temp *= nums[i-1];
            farray.push_back(temp);
        }
        
        temp=1;
        
           for(int i=nums.size()-2;i>=0;i--){
            temp *= nums[i+1];
            sarray.push_back(temp);
        }
        temp =0;
        
        while(temp != sarray.size()){
            int x = farray[temp]*sarray[nums.size() -1- temp];
            result.push_back(x);
            temp++;
        }
       return result; 
    }
};
