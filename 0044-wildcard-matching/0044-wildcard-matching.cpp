class Solution {
public:
    
    bool f(int i, int j , string &s , string &t , vector<vector<int>> &dp)
    {
        if(i<0 && j<0)
            return true ; 
        
        if(j<0 && i>=0)
            return false ; 
        
        if(j >=0 && i<0)
        {
            for(int jj=0 ; jj<=j ; jj++)
            {
                if(t[jj] != '*')
                    return false ; 
            }
            return true ; 
        }
        
        if(dp[i][j] != -1)
            return dp[i][j] ; 
        
        if(s[i] == t[j] || t[j] == '?')
            return dp[i][j] = f(i-1 , j-1 , s , t , dp) ; 
        else if(t[j] == '*')
            return dp[i][j] = f(i , j-1 , s , t , dp) || f(i-1 , j , s , t , dp) ; 
        else
            return dp[i][j]=  false ; 
    }
    
    bool isMatch(string s, string t) {
        int n = s.size() ; 
        int m = t.size() ; 
        
        vector<vector<int>> dp(n, vector<int>(m , -1)) ; 
        return f(n-1 , m-1 , s , t , dp) ; 
    }
};