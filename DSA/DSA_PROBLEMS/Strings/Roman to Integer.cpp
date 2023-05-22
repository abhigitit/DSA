class Solution {
    unordered_map<char,int> rti;
public:
    int romanToInt(string s) {
        rti['I']=1;
        rti['V']=5;
        rti['X']=10;
        rti['L']=50;
        rti['C']=100;
        rti['D']=500;
        rti['M']=1000;
        int res = 0;
        for(int i=0;i<s.size()-1;++i) {
            char curr = s[i];
            char next = s[i+1];
            if(rti[curr]<rti[next])
            {
                res-=rti[curr];
            }
            else
            {
                res+=rti[curr];
            }
        }
        res+=rti[s[s.size()-1]];
        return res;

    }
};
