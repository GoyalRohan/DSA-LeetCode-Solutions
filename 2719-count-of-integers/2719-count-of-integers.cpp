class Solution {
public:
    int mod = 1e9+7 ; 
    int dp[23][500][2]; 
    
    int digitsum(string num)
    {
        int sum = 0 ; 
        for(int i=0 ; i<num.size() ; i++)
        {
            sum += num[i]-'0' ; 
        }
        
        return sum ; 
    }
    
    
    int solve(int ind, int cursum, int tight, int min_sum, int max_sum, string num)
    {
        if(ind == num.size())
            return (cursum >= min_sum && cursum <= max_sum) ?1 :0 ; 
        
        if(dp[ind][cursum][tight] != -1)
            return dp[ind][cursum][tight] ;
        
        int ans = 0 ; 
        int end = (tight == 1) ? num[ind]-'0' : 9 ; 
        
        for(int cur=0 ; cur<=end ; cur++)
        {
            int newtight = (tight == 1 && cur == end) ? 1 : 0 ; 
            ans += solve(ind+1, cursum+cur , newtight , min_sum , max_sum , num) ; 
            ans = ans % mod ; 
        }
        
        return dp[ind][cursum][tight] = ans%mod ; 
    }
    
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp,-1,sizeof(dp));
        
        int ans = 0 ; 
        ans = solve(0 , 0 , 1 , min_sum, max_sum, num2) ; 
        
        memset(dp,-1,sizeof(dp));
        ans -= solve(0, 0 , 1, min_sum , max_sum, num1) ; 
        
        int temp = digitsum(num1); 
        
        if( temp >= min_sum && temp <=max_sum)
            ans++ ; 
        
        ans %= mod ; 
        
        return (ans+mod)%mod ; 
    }
};