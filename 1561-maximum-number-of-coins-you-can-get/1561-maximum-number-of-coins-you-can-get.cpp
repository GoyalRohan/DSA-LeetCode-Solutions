class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size() ; 
        sort(piles.begin() , piles.end()) ; 
        int i=0 , j=n-1 , score = 0 ;
        
        while(i<j-1)
        {
            j-- ; 
            score += piles[j] ; 
            j-- ; 
            i++ ; 
        }
        
        return score ; 
    }
};