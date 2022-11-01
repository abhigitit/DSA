/*
Find All Anagrams in a String (438) A

Sliding window

*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int window_size = p.size();
        if(window_size>s.size()) return {};
        
        vector<int> res;
        unordered_map<char,int> mp1;
         unordered_map<char,int> mp2;
        
        int window_start = 0;
       
        for(auto &c : p)
        {
            mp1[c]++;
        }
        
        for(int window_end=0;window_end<s.size();++window_end)
        {
            if(window_end-window_start+1>window_size)
            {
                mp2[s[window_start]]--;
                if( mp2[s[window_start]]==0)
                    mp2.erase(s[window_start]);
                window_start++;
            }
            
            mp2[s[window_end]]++;
            
            if(window_end-window_start+1==window_size)
            {
                if(mp1==mp2)
                    res.push_back(window_start);
            }
            
           
        }
        return res;
        
    }
};
