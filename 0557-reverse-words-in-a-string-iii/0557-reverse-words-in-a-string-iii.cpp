class Solution {
public:
    string reverseWords(string s) {
        int i, j ; 
        for(int i=0 ; i<s.size() ; i++ )
        {
            if(s[i] != ' ')
            {
                j=i ; 
                for(; j<s.size() && s[j] != ' '; j++)
                {}
                reverse(s.begin()+i , s.begin()+j) ;
                i = j-1 ; 
            }
             
            
            
        }
        
        return s ; 
    }
};