/*
Insert Delete GetRandom O(1) 

*/

class RandomizedSet {
public:
    set<int> s;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(!s.count(val))
        {
             s.insert(val);
            return true;
        }
        return false;   
            
    }
    
    bool remove(int val) {
         if(s.count(val))
        {
             s.erase(val);
             return true;
        }
        return false; 
    }
    
    int getRandom() {
        int idx = rand()%s.size();
        auto it = s.begin();
        for (int i = 0; i < idx; i++)
        {
            it++;
        }
        return *it;
    }
};
