/*
Rotate String
*/

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        s = s+s;
        int N = s.size();
        int M = goal.size();
        
        for(int i=0;i<=N-M;++i)
        {
            int j;
            for(j=0;j<M;++j)
            {
                if(s[i+j]!=goal[j])
                    break;
            }
            if(j==M) return true;
        }
        return false;
    }
};
