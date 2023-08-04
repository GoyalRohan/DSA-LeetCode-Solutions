class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
         unordered_set<string> myset ; 
        int n = s.size() ; 
        for(auto word : wordDict)
        {
            myset.insert(word) ; 
        }
        
        vector<int> dp(n+1 , 0) ; 
        dp[n] = 1 ; 
        
        for(int i = n-1; i>=0 ; i--)
        {
            
            string temp ; 
            for(int j = i ; j<n ; j++)
            {
                temp += s[j] ; 
                if(myset.find(temp) != myset.end())
                {
                        if(dp[j+1])
                            dp[i] = 1 ; 
                }
            }
        }
        
        return dp[0] ;
    }
};