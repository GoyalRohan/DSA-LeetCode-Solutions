class Solution {
public:

    int numDecodings(string s) {
        
        int n = s.size() ; 
        vector<int> dp(n+1 , 0) ;
        
        dp[n] = 1 ; 
        
        for(int i=n-1 ; i>=0 ; i--)
        {
            string temp = "" ; 
            int ans = 0 ; 
        
            for(int ind=i ; ind < min(i+2 , n) ; ind++)
            {
                temp += s[ind]  ;
                if(stoi(temp) == 0 || stoi(temp) > 26)
                    break  ;

                ans += dp[ind+1] ; 
            }

            dp[i] = ans ;    
        }
        
        
        
        return dp[0] ; 
        
        
    }
};