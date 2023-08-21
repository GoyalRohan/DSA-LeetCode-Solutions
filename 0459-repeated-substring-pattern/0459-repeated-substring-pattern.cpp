class Solution {
public:
    
    string temp1 = "" ; 
    
    bool repeatedSubstringPattern(string s) {
        int n = s.size() ; 
        
        for(int i=0 ; i<n-1 ; i++)
        {
            temp1 += s[i] ; 
            string temp2 = temp1 ; 
            
            while(temp2.size() < n)
            {
                temp2 += temp1 ; 
            }
            
            if(temp2 == s)
                return true ; 
        }
        
        return false ; 
    }
};