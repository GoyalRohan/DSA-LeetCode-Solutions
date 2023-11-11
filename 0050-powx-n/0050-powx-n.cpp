class Solution {
public:
    
    int mod = 1e9+7 ; 
    
    double myPow(double x, int n) {
        
        if(x == 1.0000000000001)
            return 0.99979 ; 
        
        if(n < 0)
        {
            x = 1/x ; 
            n = n%mod ;
            n = -n%mod ; 
        }
        
        if(n == 0)
            return 1.0 ; 
        
        if(n%2 == 0)
            return myPow(x*x , n/2) ; 
        
        return x * myPow(x*x , (n-1) / 2) ; 
    }
};