class Solution {
public:
    
    
    bool repeatedSubstringPattern(string s) {
        int n = s.size() ; 
        
        for(int i=n/2 ; i>=1 ; i--)
        {
            if(n % i == 0)
            {
                string temp = s.substr(0 , i) ; 
                // cout
                string newstr = "" ; 
                for(int j=1 ; j<=n/i ; j++)
                    newstr += temp ; 
                
                if(newstr == s)
                    return true ; 
                    
            }
        }
        
        return false ; 
    }
};