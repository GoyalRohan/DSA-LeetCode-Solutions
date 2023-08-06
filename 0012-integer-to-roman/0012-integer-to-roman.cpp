class Solution {
public:
    string intToRoman(int num) {
        
        string ans ; 
        vector<int> val = {1 , 4 , 5 , 9 , 10 , 40 , 50 , 90 , 100 , 400 , 500 , 900 , 1000} ;
        vector<string> notation = {"I" , "IV" , "V" , "IX" , "X" , "XL" , "L" , "XC" , "C" , "CD" , "D" , "CM" , "M"} ; 
        
        for(int pos = 12 ; pos>=0 && num>0 ; pos--)
        {
            while(num >= val[pos])
            {
                num = num - val[pos] ; 
                ans += notation[pos] ; 
            }
        }
        
        return ans ; 
    }
};