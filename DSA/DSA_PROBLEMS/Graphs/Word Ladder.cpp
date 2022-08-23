/*
Leetcode: Word Ladder

Intuition : All the words form a graph. Adjancent nodes differ by one charcater. Should perform BFS to find shortest path between beginning
and ending words.


To avoid n^2*m while creating adjacency list, we use a smart approach. 
Consider word hot => It can fall into any pattern with one charater differing => *ot, h*t,ho*
Consider word dot => It can fall into any pattern with one charater differing => *ot, d*t,do*
We can see that these words have one pattern in common.
Using these patterns as key of hashmap and list of words as values, we create adjacency list.



TC: O(n^2 * m ); n^2 comes from comparing one word to all other which is the number of potential edges and m is the length of the word.
https://www.youtube.com/watch?v=h9iTnkgv05E&ab_channel=NeetCode

*/

class Solution {
public:
    map<string,vector<string>> pattern_store;
    unordered_set<string> wordList_set;
    unordered_set<string> visited;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for(auto s:wordList)
        {
            wordList_set.insert(s);
        }
        
        if(!wordList_set.count(endWord))
            return 0;
        
        wordList.push_back(beginWord);
        for(auto i:wordList)
        {
            for(int j=0;j<i.size();++j)
            {
                string pattern = i;
                pattern[j]='*';
                pattern_store[pattern].push_back(i);
            }
        }
        queue<string> BFS;
        BFS.push(beginWord);
        visited.insert(beginWord);
        int res = 1;
        while(!BFS.empty())
        {
            int n = BFS.size();
            for(int i=0;i<n;++i)
            {
                string word = BFS.front();
                BFS.pop();
                if(word==endWord)
                    return res;
                for(int j=0;j<word.size();++j)
                {
                    string pattern = word;
                    pattern[j]='*';
                    for(auto nei:pattern_store[pattern])
                    {
                        if(!visited.count(nei))
                        {
                            visited.insert(nei);
                            BFS.push(nei);
                        }
                            
                    }
                }
            }
            res++;
        }
        return res;
    }
};
