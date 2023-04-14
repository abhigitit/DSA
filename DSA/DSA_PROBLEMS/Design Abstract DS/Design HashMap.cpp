/*
Design HashMap
https://www.youtube.com/watch?v=xVEGczCJCHs&t=586s

*/
class MyHashMap {
    vector<list<pair<int,int>>> mp;
    int sze;
public:
    MyHashMap() {
        sze = 100;
        mp.resize(sze);
    }
     int hash(int key)
    {
        return key%sze;
    }

    void put(int key, int value) {
        int idx = hash(key);
        remove(key);
        mp[idx].push_back({key,value});
    }
    
    list<pair<int,int>> :: iterator search(int key)
    {
        int idx = hash(key);
        list<pair<int,int>> :: iterator it = mp[idx].begin();
        while(it!=mp[idx].end())
        {
            if(it->first==key) return it;
            it++;

        }
        return it;
    }
    int get(int key) {
        if(!contains(key)) return -1;
        return search(key)->second;
    }
    
    void remove(int key) {
         if(!contains(key)) return;
         int idx = hash(key);
        mp[idx].erase(search(key));
    }

    bool contains(int key)
    {
        int idx = hash(key);
        if(search(key)!=mp[idx].end()) return true;
        return false;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
