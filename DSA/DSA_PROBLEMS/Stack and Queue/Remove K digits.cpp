/*

Leetcode : 402

Intuition: Left most digits have more weightage and greater numbers from the left have greater weightage and can be removed. Wherever there is a 
dip in the graph, that element can be removed. Make use of stack to achieve this.

https://www.youtube.com/watch?v=3QJzHqNAEXs&ab_channel=TECHDOSE

TC:O(N)
SC:O(N)

*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> temp;
        string res;
        
        for(auto c:num)
        {
            
            while(!temp.empty() and k>0 and c<temp.top())
            {
                temp.pop();
                k--;
            }
            if(!temp.empty() or c!='0')
                temp.push(c);
        }
        
        while(!temp.empty() and k--)
            temp.pop();
        
        if(temp.empty()) return "0";
        
        while(!temp.empty())
        {
            res+=temp.top();
                temp.pop();
        }
        reverse(res.begin(),res.end());
            
        return res;
      
    }
};
