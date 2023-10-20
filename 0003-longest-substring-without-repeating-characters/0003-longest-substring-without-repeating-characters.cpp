class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size() ; 
        int start = 0 , end = 0 ; 
        unordered_set<char> myset ; 
        int maxlen = 0 ; 
        
        for(end=0 ; end<n ; end++)
        {
            if(myset.find(s[end]) == myset.end())
            {
                myset.insert(s[end]) ; 
                maxlen = max(maxlen , end-start+1) ; 
            }
            else
            {
                while(myset.find(s[end]) != myset.end())
                {
                    myset.erase(s[start]) ; 
                    start++ ; 
                }
                
                myset.insert(s[end]) ;    
                maxlen = max(maxlen , end-start+1) ; 
            }
        }
        
        return maxlen ; 
    }
};