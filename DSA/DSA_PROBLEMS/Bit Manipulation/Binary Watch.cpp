
/*
Leetcode  401
Intuition : Loop over all possible hours and minutes and check the bitset count of hours+min == given number

TC: O(12*60)

*/

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        
       vector<string> res;
        for(int hours = 0; hours<12 ;++hours)
        {
            for(int min = 0; min < 60 ;min++)
            {
                if(countSetBits(hours) + countSetBits(min) == turnedOn)
                {
                    if(min<10)
                    {
                         res.push_back(to_string(hours) + ':' + to_string(0) + to_string(min));
                    }
                else
                    res.push_back(to_string(hours) + ':' + to_string(min));
                }
              
            }
        }
      
        return res;
    }
    int countSetBits(int n)
{
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
};
