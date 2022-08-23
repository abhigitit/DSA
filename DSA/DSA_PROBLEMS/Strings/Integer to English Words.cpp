
/*
Leetcode 272
TC:O(1)
SC:O(1)
*/
vector<string> ones ={"","One ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine ","Ten ","Eleven ","Twelve ","Thirteen ","Fourteen ","Fifteen ","Sixteen ","Seventeen ","Eighteen ","Nineteen "};
vector<string> tens={"","","Twenty ","Thirty ","Forty ","Fifty ","Sixty ","Seventy ","Eighty ","Ninety "};


class Solution {
public:
   string convert(int num, string suffix)
   {
       string str = "";
       if(num>99 and num%100 > 19)
       {
           str+= ones[num/100] + "Hundred " + tens[(num/10)%10] + ones[num%10];
       }
         else if(num>99 and num%100 < 19)
       {
           str+= ones[num/100] + "Hundred " +  ones[num%100];
       }
       else if(num>19)
       {
           str+= tens[num/10] + ones[num%10];
       }
       else
           str+= ones[num];
       if(num)
           str+=suffix;
       return str;
           
   }
    
        
    
    string numberToWords(int num) {
      if(num==0) return "Zero";
        string res ="";
        res+= convert(num/1000000000,"Billion ");
        res+= convert((num/1000000)%1000, "Million ");
        res+= convert((num/1000)%1000, "Thousand ");
        res+= convert((num/100)%10, "Hundred ");
        res+= convert(num%100, "");
        if(res.size()>0)
        res.pop_back();
        return res;
        
    }
};
