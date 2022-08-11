
/*
Leetcode Text Justification

TC: O(lines*maxwidth)

Intuition: https://www.youtube.com/watch?v=GqXlEbFVTXY&t=1414s&ab_channel=MichaelMuinos

*/
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
       int i = 0;
        int n = words.size();
        vector<string> res;
        while(i<n)
        {
            int j = i+1;
            int line_len = words[i].size();
            while(j<n and (line_len + words[j].size() + (j-i-1))<maxWidth)
            {
                line_len+= words[j].size();
                j++;
                
            }
            
            int number_of_words = j-i;
            int spaces = maxWidth - line_len;
            if(number_of_words==1 or j>=n) res.push_back(leftJustified(i,j,spaces,words));
            else
                res.push_back(centerJustified(i,j,spaces,words));
            i=j;
        }
        return res;
    }
    
    string leftJustified(int i,int j, int spaces,vector<string>& words)
    {
        int spaces_in_between = j-i-1;
        int spaces_on_right = spaces - spaces_in_between;
        string temp = words[i];
        for(int k=i+1;k<j;++k)
        {
            temp+= " " + words[k];
        }
        while(spaces_on_right--)
        {
            temp+=" ";
        }
        return temp;
    }
    
    string centerJustified(int i,int j, int spaces,vector<string>& words)
    {
        int spaces_in_between = spaces/(j-i-1);
        int extra_spaces = spaces%(j-i-1);
        string temp = words[i];
         for(int k=i+1;k<j;++k)
        {
             int spaces_to_add = spaces_in_between + (extra_spaces-- >0 ? 1 : 0);
             while(spaces_to_add--)
             {
                 temp+= " ";
             }
            temp+=words[k];
        }
        return temp;
    }
};
