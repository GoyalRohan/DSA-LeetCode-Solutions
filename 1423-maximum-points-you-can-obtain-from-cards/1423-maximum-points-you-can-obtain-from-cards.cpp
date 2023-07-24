class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size() ; 
        int maxi = 0  , sum = 0; 
        
         int prefix = 0 ; 
        
        for(int i=0 ; i<k ; i++)
        {
            prefix += cardPoints[i] ; 
        }
        
        int cur = prefix ;
        for(int i=k-1 ; i>=0 ; i--)
        {
            cur = cur - cardPoints[i] ; 
            cur += cardPoints[n-k+i] ; 
            
            prefix = max(prefix , cur) ; 
        }
        
        
        return prefix ;
    }
};