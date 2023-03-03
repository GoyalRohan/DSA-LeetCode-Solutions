class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size() , n = needle.size() ; 
        
        for(int i=0 ; i<=(m-n) ; i++)
        {
            int count = 0 ; 
            for(int j = 0 ; j<n ; j++)
            {
                if(needle[j] == haystack[i+j])
                    count++ ; 
            }
            
            if(count == n)
                return i  ; 
        }
        
        return -1 ; 
    }
};