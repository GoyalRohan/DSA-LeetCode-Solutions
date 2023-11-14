class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size() ; 
        vector<int> left(26,0) , right(26,0) ; 
        unordered_set<string> myset ; 
        
        for(int i=0 ; i<n ; i++)
        {
            right[s[i]-'a']++ ; 
        }
        
        for(int i=0 ; i<n ; i++)
        {
            right[s[i]-'a']-- ; 
            for(int j=0 ; j<26 ; j++)
            {
                if(left[j] > 0 && right[j]>0)
                {
                    char x = j + 'a' ; 
                    string pal = "" ;
                    pal += x ; 
                    pal += s[i] ; 
                    pal += x ; 
                    myset.insert(pal) ; 
                }
            }
            
            left[s[i]-'a']++ ; 
        }
        
        return myset.size() ; 
    }
};