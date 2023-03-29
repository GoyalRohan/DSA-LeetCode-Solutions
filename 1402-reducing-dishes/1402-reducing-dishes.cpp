class Solution {
public:
    
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size() ; 
        sort(satisfaction.begin() , satisfaction.end()) ; 
        
        vector<int> cur(n+1 , 0) , next(n+1 , 0) ; 

        
        for(int i=n-1 ; i>=0 ; i--)
        {
            for(int count=i ; count>=0 ; count--)
            {
                int notTake = 0 + next[count] ; 
        
                int take = satisfaction[i] * (count+1) + next[count+1] ;
                cur[count] = max(take, notTake) ; 
                
                
            }
                next = cur ; 
        }
        
        
        return next[0] ;
    }
};