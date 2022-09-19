/*

Snapshot Array

Intuition: Every version of array can be stored as value in the map. But if only one element changes, why have a copy of rest others. More memory usage.

Use map of map. Store a particular index which is changed for a snapid. When asked for any other index for the same id, we can check previous snap ids
to return the element.

TC: O(1) insert
O(snapids) retrieval

*/
Efficient solution:
class SnapshotArray {
public:
unordered_map<int,unordered_map<int,int>> hmap;
    int snapid=0;
    SnapshotArray(int length) {
        
    }
    
    void set(int index, int val) {
        hmap[snapid][index]=val;
        
    }
    
    int snap() {
        snapid++;
        return snapid-1;
    }
    
    int get(int index, int snap_id) {
        
        for(int i=snap_id;i>=0;i--)
        {
            if(hmap[i].count(index)==1)
                return hmap[i][index];
        }
        return 0;
    }
};

My initial solution which takes more memory
class SnapshotArray {
public:
    int snap_id;
    vector<int> arr;
    map<int,vector<int>> cache;
    SnapshotArray(int length) {
        arr.resize(length);
        snap_id = 0;
        
    }
    
    void set(int index, int val) {
        arr[index] = val;
          
    }
    
    int snap() {
        cache[snap_id++] = arr;
        return snap_id -1;
    }
    
    int get(int index, int snap_id) {
        return cache[snap_id][index];
    }
};
