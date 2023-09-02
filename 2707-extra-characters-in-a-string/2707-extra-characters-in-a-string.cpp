class Solution {
public:
    
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size() ; 
        unordered_set<string> myset(dictionary.begin(), dictionary.end()) ; 
        
        vector<int> dp(n+1 , 0) ;
        
        for(int ind=n-1 ; ind>= 0 ; ind--)
        {
            int mini = 1e9 ; 
            for(int i=ind ; i<s.size() ; i++)
            {
                string word = s.substr(ind , i-ind+1) ;
                if(myset.find(word) != myset.end())
                {
                    mini = min(mini , dp[i+1]) ; 
                }
                else
                {
                    mini = min (mini, i - ind + 1 + dp[i+1]) ; 
                }
            }

             dp[ind] = mini ; 
        }

        
        return dp[0] ; 
    }
};