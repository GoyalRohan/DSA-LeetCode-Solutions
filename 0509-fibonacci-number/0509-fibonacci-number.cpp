class Solution {
public:
    int fib(int n) {
        // n = n-1 ; 
        if(n <= 1)
            return n ; 
        
        int prev1 = 0 , prev = 1 ; 
        
        for(int i=2 ; i<=n ; i++)
        {
            int cur = prev + prev1 ; 
            prev1 = prev ; 
            prev = cur ; 
        }
        
        return prev ; 
    }
};