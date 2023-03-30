/*
Repeated DNA Sequences
*/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        string temp="";
        set<string> seen;
        set<string> res;

        for(int i=0;i<10 and i<s.size();i++)
        {
            temp+=s[i];
        }
     
        seen.insert(temp);

        for(int i=10;i<s.size();++i)
        {
            temp.erase(0, 1);
            temp+=s[i];
            
            if(seen.count(temp))
                res.insert(temp);
            else
                seen.insert(temp);
        }

        vector<string> res2(res.begin(), res.end());
        return res2;
    }
};
