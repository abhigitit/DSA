/*
Fruit Into Baskets

https://www.youtube.com/watch?v=s_zu2dOkq80&ab_channel=NickWhite

Longest Contiguos Subarray of only two numbers

exaplination of else statement : curr_max = last_fruit_count+1;
3,3,3,1,2...when on 2, we have seen a new fruit other than 3,1 so currmax = lastfruit(1) count + 1(new fruit 2).
*/


 class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int last_fruit = -1;
        int second_last_fruit = -1;
        int last_fruit_count = 0;
        int curr_max=0;
        int res = 0;
        
        for(auto fruit: fruits)
        {
            if(fruit == last_fruit or fruit == second_last_fruit)
            {
                curr_max++;
            }
            else{
                curr_max = last_fruit_count+1;
            }
            
            if(fruit == last_fruit)
                last_fruit_count++;
            else
            {
                second_last_fruit = last_fruit;
                 last_fruit=fruit;
                  last_fruit_count=1;
            }


            res = max(res,curr_max);
        }
        
        return res;
    }
};
