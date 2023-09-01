class Solution {
public:
    
    int gcd(int m , int n)
    {
        if(n == 0)
            return m ; 
        
        return gcd(n , m%n) ; 
    }
    
    bool canMeasureWater(int x, int y, int z) {
        
        if(x+y < z)
            return false ; 
        
        int div = gcd(x, y) ; 
        if(z%div == 0)
            return true ; 
        
        return false; 
        
    }
};