/*
Longest Repeating Character Replacement
Max Consecutive Ones III

Intuition : Current window size - highest repated character in current = count of remaining characters in the window. If this count equals k, we can afford
to change them and if this count becomes greater than k, we need to pop from starting of the window.

https://www.youtube.com/watch?v=00FmUN1pkGE&ab_channel=NickWhite

*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int> count_char;
        int max_length = 0;
        int max_count_char = 0;
        int window_start = 0;
        
        for(int window_end=0; window_end<s.size(); ++window_end)
            
        {
            count_char[s[window_end]]++;
            int char_count = count_char[s[window_end]];
            max_count_char = max(max_count_char,char_count);
            
            while(window_end - window_start + 1 - max_count_char > k)
            {
                count_char[s[window_start]]--;
                window_start++;
            }
            
            
            max_length = max(max_length,window_end - window_start + 1 );
        }
