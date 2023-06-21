class Solution {
public:
    
    
    string shortestCommonSupersequence(string s, string t) {
        int n =s.size() ; 
        int m = t.size() ; 
        vector<vector<int>> dp(n+1 , vector<int>(m+1 , 0)) ; 

        for(int ind1=0 ; ind1<=n ; ind1++)
            dp[ind1][0] = 0 ; 
        for(int ind2=0 ; ind2<=m ; ind2++)
            dp[0][ind2] = 0 ; 

        for(int ind1=1 ; ind1<=n ; ind1++)
        {
            for(int ind2=1 ; ind2<=m ; ind2++)
            {
                if(s[ind1-1] == t[ind2-1])
                    dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1] ;
                else
                    dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2] , dp[ind1][ind2-1]) ; 
            }
        }

       string ans = "" ;
       int i=n , j = m ; 
       
       while(i>0 && j >0)
       {
           if(s[i-1] == t[j-1])
           {
               ans += s[i-1] ; 
               i-- ; j-- ; 
           }
           else if(dp[i-1][j] > dp[i][j-1])
           {
               ans += s[i-1] ; 
               i-- ; 
           }
           else
           {
               ans += t[j-1] ; 
               j-- ; 
           }
       }
        
        while(i > 0)
        {
            ans += s[i-1] ; 
            i-- ; 
        }
        
        while(j > 0)
        {
            ans += t[j-1] ; 
            j-- ; 
        }
           
        reverse(ans.begin() ,ans.end()) ; 
        return ans ; 
    }
};