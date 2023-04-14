/*
Design HashSet
https://www.youtube.com/watch?v=IjxkD8L2cOM

using chaining concept ; list stl which is doubly linked list
*/

class MyHashSet {
    vector<list<int>> set;
    int sze;
public:
    MyHashSet() {
        sze = 90;
        set.resize(sze);
    }
    int hash(int key)
    {
        return key%sze;
    }
    void add(int key) {
        if(contains(key)) return;
        int idx = hash(key);
        set[idx].push_back(key);

    }
    list<int> :: iterator search(int key)
    {
        int idx = hash(key);
        return find(set[idx].begin(), set[idx].end(),key);


    }
    void remove(int key) {
        if(!contains(key)) return;
        int idx = hash(key);
        set[idx].erase(search(key));
    }
    
    bool contains(int key) {
        int idx = hash(key);
        if(search(key)!=set[idx].end()) return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
