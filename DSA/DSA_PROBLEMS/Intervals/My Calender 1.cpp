/*

729. My Calendar I

Intuition 1: For every call, store start as key and end as the value in map. When there is a new entry, loop over the map and check if the new entry fits in
correctly i.e the new start time should be greater than or equal to the end time that is being compared or new end time should be less than start time of already 
present.


Intuition 2: Mark +1 for start time and -1 for end time. Use ordered map and calculate the sum. If the sum exceeds 1, then return false
https://www.youtube.com/watch?v=lUROQC6YCNQ&ab_channel=CodewithAlisha

*/

1;
class MyCalendar {
    unordered_map<int, int>bookings;
public:    
    bool book(int s1, int e1) {
        for(auto& [s2, e2] : bookings) 
            if( !(s1 >= e2 || s2 >= e1) )   // if neither of above condition is satisfied, there exists an intersection
			    return false; 
        bookings[s1] = e1;                 // no intersection found, so insert the new slot and return true
        return true;
    }
};

2:
class MyCalendar {
    map<int, int>bookings;
public:    
    bool book(int s1, int e1) { 
        bookings[s1]++;   
        bookings[e1]--;
        int sum=0;
        for(auto s:bookings)
        {
            sum+=s.second;
            if(sum>1)
            {
                bookings[s1]--;
                bookings[e1]++;
                return false;
            }
                
        }
        return true;
    }
};
