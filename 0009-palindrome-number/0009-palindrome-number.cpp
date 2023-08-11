class Solution {
public:
    
    int findReverse(int num)
    {
        long long rev = 0 ; 
        while(num > 0)
        {
            int rem = num%10 ; 
            rev = rev*10 + rem ; 
            num = num/10 ; 
        }
        return rev ; 
    }
    
    bool isPalindrome(int x) {
        if(x < 0)
            return false ; 
        
        int rev = findReverse(x);
        if(x == rev)
            return true ; 
        return false ;
    }
};