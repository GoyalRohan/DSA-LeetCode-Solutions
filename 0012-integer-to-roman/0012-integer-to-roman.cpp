class Solution {
public:
    string intToRoman(int num) {
        
        string ans ; 
        vector<int> val = {1 , 4 , 5 , 9 , 10 , 40 , 50 , 90 , 100 , 400 , 500 , 900 , 1000} ;
        vector<string> notation = {"I" , "IV" , "V" , "IX" , "X" , "XL" , "L" , "XC" , "C" , "CD" , "D" , "CM" , "M"} ; 
        
        for(int pos = 12 ; pos>=0 && num>0 ; pos--)
        {
            
                int temp = num/val[pos] ; 
                if(temp == 0)
                    continue ; 
            
                num = num%val[pos] ; 
                while(temp>0)
                {
                    ans += notation[pos] ; 
                    temp-- ; 
                }

                
        }
        
        return ans ; 
    }
};