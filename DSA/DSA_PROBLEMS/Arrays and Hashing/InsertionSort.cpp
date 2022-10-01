
/*
Insertion Sort : Consider first element is part of sorted subset and start looping from second element. Fill a void in second element's position and store the value
in a variable. Now check if previous element is greater than the value, if its greater move it to the right (move hole/void to the left) and insert the value 
in correct position.

*/


#include <bits/stdc++.h>

using namespace std;

void insertion_sort(vector<int>& input)
{
    
    for(int i=1;i<input.size();++i)
    {
        int hole = i;
        int value = input[i];
        while(hole>0 and input[hole-1]>value)
        {
            input[hole]=input[hole-1];
            hole--;
        }
        input[hole]=value;
    }
}

int main()
{
    vector<int> input = {3,1,7,2,94,54,12};
    
    insertion_sort(input);
    
    for(auto i:input)
    {
        cout<<i<<endl;
    }

    return 0;
}
