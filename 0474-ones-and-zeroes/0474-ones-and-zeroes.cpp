class Solution {
public:
    
    void countZeroAndOnes(int &nom, int &non, string str)
    {
        for(auto s:str)
        {
            if(s == '0')
                nom++ ; 
            else
                non++ ;
        }
    }
    
    int solve(int ind , int m , int n , vector<string>& strs, vector<vector<vector<int>>> &dp)
    {
        
        if(ind >= strs.size())
            return 0 ; 
        
        if(m == 0 && n == 0)
            return 0 ; 
        
        if(dp[ind][m][n] != -1)
            return dp[ind][m][n] ; 
        
        int nom = 0 , non = 0 ; 
        countZeroAndOnes(nom , non , strs[ind]) ; 
        
        int notTake = INT_MIN , take = INT_MIN ; 
        if(m >= nom && n >= non)
            take = 1 + solve(ind+1 , m-nom , n-non , strs, dp) ; 
        
        notTake = solve(ind+1 , m , n , strs, dp) ; 
        
        return dp[ind][m][n] =  max(take, notTake) ; 
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size() ; 
        vector<vector<vector<int>>> dp(size , vector<vector<int>>(m+1 , vector<int>(n+1 , -1))) ; 
        return solve(0 , m , n, strs , dp) ; 
    }
};