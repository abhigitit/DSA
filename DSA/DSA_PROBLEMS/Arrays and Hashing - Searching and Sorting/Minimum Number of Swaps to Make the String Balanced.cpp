/*
Minimum Number of Swaps to Make the String Balanced
*/
class Solution {
public:
    int minSwaps(string s) {
        int max_closing = INT_MIN;
        int count = 0;
        for(auto i:s)
        {
            if(i==']')
                count++;
            if(i=='[')
                count--;
            max_closing = max(max_closing, count);
        }
        return (max_closing+1)/2;
    }
};
