class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size() , n = needle.size() ; 
        
        for(int i=0 ; i<=(m-n) ; i++)
        {
            bool isfound = true ; 
            for(int j = 0 ; j<n ; j++)
            {
                if(needle[j] != haystack[i+j])
                {
                    isfound = false ; 
                    break ;
                }
                    
            }
            
            if(isfound == true)
                return i  ; 
        }
        
        return -1 ; 
    }
};