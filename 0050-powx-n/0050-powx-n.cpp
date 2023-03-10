class Solution {
public:
    
    int mod = (int) 1e9 + 7 ; 
    
    double myPow(double x, int n) {
        
        if(n < 0)
        {
            x = 1/x ;
            n = n%mod ; 
            n = -n%mod ; 
        }
             
            
        
        if(n == 0)
            return 1 ; 
        
        if(n%2 == 0)
            return myPow(x * x , n/2) ; 
        
        return x * myPow(x * x , (n-1)/2) ; 
        
    }
};