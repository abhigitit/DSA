/*
Trie Insert and Search
https://drive.google.com/file/d/1w6UpLK6HwkAQcvZ6BaK_DQy09_sf3aE0/view
TC for insertion and searching is O(N)
https://www.youtube.com/watch?v=0k79LqIaHyQ&ab_channel=TECHDOSE
*/

#include <bits/stdc++.h>
using namespace std;


struct TrieNode{
    int wc;
    TrieNode* child[26];
    char data;
};

TrieNode nodepool[1000];
TrieNode* root;
int poolcount;

void init()
{
    poolcount=0;
    root = &nodepool[poolcount++];
    root->data = '/';
    for(register int i=0;i<26;++i)
    {
        root->child[i]=NULL;
    }
}

TrieNode* getNode(char c)
{
  TrieNode* newnode = &nodepool[poolcount++];
   for(register int i=0;i<26;++i)
    {
        newnode->child[i]=NULL;
    }
    newnode->wc = 0;
    newnode->data = c;
    return newnode;
}

void insert(string word)
{
    TrieNode* curr = root;
    int index;
    for(int i=0;i<word.size();++i)
    {
         index = word[i]-'a';
        if(curr->child[index]==NULL)
        {
           curr->child[index] = getNode(word[i]); 
        }
        curr->child[index]->wc +=1;
        curr = curr->child[index];
    }
}

bool search(string word)
{
    TrieNode* curr = root;
    int index;
    for(int i=0;i<word.size();++i)
    {
         index = word[i]-'a';
        if(curr->child[index]==NULL or curr->child[index]->wc==0)
        return false;
        curr=curr->child[index];
        
    }
    return true;
}

int count_with_prefix(string word)
{
    TrieNode* curr = root;
    int index;
    for(int i=0;i<word.size();++i)
    {
         index = word[i]-'a';
        if(curr->child[index]==NULL or curr->child[index]->wc==0)
        return 0;
        curr=curr->child[index];
        
    }
    return curr->wc;
}


int main()
{
    init();
    string a = "abhiteja";
    string b = "abhi";
    string c = "vineet";
    string d = "sidhu";
    string e = "sidha";
    string f = "vikram";
    insert(a);
    insert(b);
    insert(c);
    insert(d);
    insert(e);
    insert(f);
cout<<search(b)<<endl;
cout<<count_with_prefix("sidhu");


    return 0;
}
