class Solution {
public:
    
    bool solve(int ind1, int ind2 , int k, string s1 , string s2 , string s3, vector<vector<int>> &dp)
    {
        if(k==0)
            return true ; 
        
        if(dp[ind1][ind2] != -1)
            return dp[ind1][ind2] ; 
        
        bool ans = false ; 

        if(ind1-1 >= 0 && s1[ind1-1] == s3[k-1])
            ans = ans || solve(ind1-1 , ind2 , k-1, s1 , s2 , s3 , dp) ; 

        if(ind2-1 >= 0 && s2[ind2-1] == s3[k-1])
            ans = ans || solve(ind1 , ind2-1 , k-1, s1 , s2 , s3, dp) ; 
        
        
        return dp[ind1][ind2] = ans ; 
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size() , m = s2.size() , k = s3.size()  ; 
        if(n+m != k)
            return false ; 
        
        vector<vector<int>> dp(n+1 , vector<int>(m+1 , -1)) ; 
        return solve(n , m , k, s1 , s2 , s3 , dp) ; 
        
        
    }
};