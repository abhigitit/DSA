/*
Insert Delete GetRandom O(1) 
Leetcode

O(1) search in array when rand() is assumed to be const
*/


 class RandomizedSet {
public:
map<int,int> mp;
vector<int> helper;
int index;
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(mp.count(val))
          return false;
   
        helper.push_back(val);
        mp[val] = helper.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(!mp.count(val))
          return false;
        
        int temp_idx = mp[val];
        swap(helper[temp_idx],helper[helper.size()-1]);
        helper.pop_back(); 
        mp[helper[temp_idx]] = temp_idx;
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return helper[rand()%helper.size()];
    }
};
