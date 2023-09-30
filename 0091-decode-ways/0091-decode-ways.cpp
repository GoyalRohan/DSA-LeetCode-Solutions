class Solution {
public:
    map<string , char> mpp; 
    
    int solve(int i, int n, string s , map<string , char> &mpp, vector<int> &dp)
    {
        if(i == n)
            return 1 ; 
        
        if(dp[i] != -1)
            return dp[i] ; 
        
        string temp = "" ; 
        int ans = 0 ; 
        
        for(int ind=i ; ind < min(i+2 , n) ; ind++)
        {
            temp += s[ind]  ;
            if(mpp.find(temp) == mpp.end())
                break ; 
            
            ans += solve(ind+1 , n , s , mpp , dp) ; 
        }
        
        return dp[i] = ans ; 
    }
    
    int numDecodings(string s) {
        
        int n = s.size() ; 
        for(int i=0 ; i<26 ; i++)
        {
            mpp[to_string(i+1)] = 'A' + i ; 
        }
        
        vector<int> dp(n , -1) ; 
        return solve(0 , n , s , mpp , dp) ; 
        
        
    }
};