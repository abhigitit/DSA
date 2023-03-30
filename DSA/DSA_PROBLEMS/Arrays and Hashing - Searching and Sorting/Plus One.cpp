/*
 Plus One
 */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int i = digits.size()-1;
        while(i>=0)
        {
            int curr = digits[i];
            curr+=carry;
            carry = curr/10;
            curr = curr%10;
            digits[i--] = curr;

            if(!carry)
                break;
            
        }

        if(carry)
            digits.insert(digits.begin(), 1);
        
        return digits;
    }
};
