class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> myset ; 
        myset.insert(n) ; 
        
        while(true)
        {
           int sum = 0 ; 
            while(n > 0)
            {
                sum +=(n%10) * (n%10) ; 
                n = n/10 ; 
            }
            cout<<sum<<endl ; 
            if(sum == 1)
                return true ; 
            
            if(myset.find(sum) != myset.end())
                return false ; 
            
            myset.insert(sum) ; 
            n = sum ; 
        }
        
        return false ; 
    }
};