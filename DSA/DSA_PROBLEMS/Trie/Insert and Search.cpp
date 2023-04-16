/*
Trie Insert and Search
https://www.youtube.com/watch?v=dBGUmUQhjaM&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp
TC for insertion and searching is O(N)

Coding Ninja
*/

/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
struct Node{
Node* links[26];
bool flag = false;

bool containsKey(char ch) {
    return links[ch-'a']!=nullptr;
}

void put(char ch, Node* node) {
    links[ch-'a'] = node;
}

Node* getNext(char ch) {
    return links[ch-'a'];
}

bool isEnd()
{
    return flag;
}

void setEnd()
{
    flag = true;
}
};

class Trie {
Node* root;
public:

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = root;

        for(int i=0;i<word.size();++i)
        {
            int ch = word[i];
            if(!node->containsKey(ch))
            {
                node->put(ch, new Node());
            }
            node = node->getNext(ch);
        }
        node->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node = root;
        for(int i=0;i<word.size();++i) {
            char ch = word[i];
            if(!node->containsKey(ch))
                return false;
            node = node->getNext(ch);
        }
        return node->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
         Node* node = root;
        for(int i=0;i<prefix.size();++i) {
            char ch = prefix[i];
            if(!node->containsKey(ch))
                return false;
            node = node->getNext(ch);
        }
        return true;

    }
};
