class Solution {
public:
    
    int solve(int ind , string s, unordered_set<string> &myset, vector<int> &dp)
    {
        if(ind >= s.size())
            return 0 ; 
        
        if(dp[ind] != -1)
            return dp[ind] ; 
        
        int mini = 1e9 ; 
        for(int i=ind ; i<s.size() ; i++)
        {
            string word = s.substr(ind , i-ind+1) ;
            if(myset.find(word) != myset.end())
            {
                mini = min(mini , solve(i+1 , s , myset, dp)) ; 
            }
            else
            {
                mini = min (mini, i - ind + 1 + min(mini , solve(i+1 , s , myset, dp))) ; 
            }
        }
        
        return dp[ind] = mini ; 
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size() ; 
        unordered_set<string> myset(dictionary.begin(), dictionary.end()) ; 
        
        vector<int> dp(n , -1) ; 
        
        return solve(0 , s , myset , dp) ; 
    }
};