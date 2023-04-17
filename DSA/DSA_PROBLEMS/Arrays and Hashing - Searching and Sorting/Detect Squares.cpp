/*
Detect Squares
*/

class DetectSquares {
    map<pair<int,int>,int> ds;
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        ds[{point[0],point[1]}]++;
    }
    
    int count(vector<int> point) {
        int px = point[0];
        int py = point[1];
        int res =0;
        for(auto it:ds)
        {
  
            int x = it.first.first;
            int y = it.first.second;
            if(abs(py-y) != abs(px-x) or px==x or py==y) continue;

            res+= ds[{x,py}]*ds[{px,y}]*ds[{x,y}];

        }
        return res;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
