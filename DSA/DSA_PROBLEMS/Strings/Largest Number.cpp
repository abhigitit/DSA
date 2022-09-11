/*

Leetcode: 179
https://www.youtube.com/watch?v=WDx6Y4i4xJ8&ab_channel=NeetCode
*/

  bool comparefn(string n1,string n2)
    {
        if(n1+n2 > n2+n1)
            return true;
        else
            return false;
    }

class Solution {
public:
   
    string largestNumber(vector<int>& nums) {
        vector<string> temp;
        for(auto i:nums)
        {
            temp.push_back(to_string(i));
        }
        
        sort(temp.begin(),temp.end(),comparefn);
        
       string res;
        for(auto i:temp)
        {
            res+=i;
        }
        if(res[0]=='0') return to_string(stoi(res));
        return res;
        
    }
   
};
