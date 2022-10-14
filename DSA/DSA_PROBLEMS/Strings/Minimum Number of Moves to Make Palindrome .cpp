/*
Minimum Number of Moves to Make Palindrome 
https://www.youtube.com/watch?v=EpuC64ClV8k&ab_channel=BroCoders

Intuition : aabb
left pointer on 'a' and right pointer on 'b'. a!=b so search for b and bring it to where left pointer is by performing adjacent swaps.
This is adjusting second half. We can similariy adjust first half by finding 'a' and getting it to the right pointer.

Fix one half, change the other half accordingly.

Consider abb..we fix 'a' and start from last b to search for another 'a'. But we end up at the left pointer. In this case, this has to be the middle element 
because there is only one such character.

TC:O(n^2)
*/
class Solution {
public:
    int minMovesToMakePalindrome(string s) {
       
        int n = s.size();
        int lt = 0;
        int rt = n-1;
        int ans=0;
        while(lt<rt)
        {
            int l=lt;
            int r=rt;
            while(s[l]!=s[r]) r--;
            
            if(l==r) //only one such char
            {
                swap(s[r],s[r+1]);
                ans++;
                continue;
            }
            else
            {
                while(r<rt)
                {
                   swap(s[r],s[r+1]);
                    r++;
                  ans++; 
                }
            }
            lt++;
            rt--;
        }
        return ans;
    }
};
