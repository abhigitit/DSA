/*
Destroying Asteroids

*/

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        unsigned long temp = mass;
        for(auto i:asteroids)
        {
            if(temp>=i)
                temp+=i;
            else
                return false;
        }
        return true;
    }
};
