/*
Generate Parentheses

https://www.youtube.com/watch?v=s9fokUqJ76A&ab_channel=NeetCode
*/

class Solution {
public:
    int n;
    vector<string> res;
    string temp;
    vector<string> generateParenthesis(int n) {
  
        this->n = n;
        temp="";
        backtrack(0,0);
        return res;
    }
    
    void backtrack(int open,int close)
    {
        if(open==n and close==n)
        {
            res.push_back(temp);
            return;
        }
        
        if(open<n)
        {
           temp+='(';
            backtrack(open+1,close);
            temp.pop_back();
        }
        
        if(close<open)
        {
            temp+=')';
            backtrack(open,close+1);
            temp.pop_back();  
        }
            
    }
};
