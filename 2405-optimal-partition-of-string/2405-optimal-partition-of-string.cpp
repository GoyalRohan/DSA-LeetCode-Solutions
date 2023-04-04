class Solution {
public:
    

    
    int partitionString(string s) {
        int i = 0, count=0 ; 
        int n = s.size() ; 
        unordered_set<char> myset ; 
        
        while(i < n)
        {
            while(i<n && myset.find(s[i]) == myset.end())
            {
                myset.insert(s[i]) ; 
                i++ ; 
            }
            
            count++ ; 
            myset.clear() ; 
        }
        
        return count ; 
    }
};