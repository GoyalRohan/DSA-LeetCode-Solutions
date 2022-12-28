class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size() ;
        
        priority_queue<int> pq(piles.begin() , piles.end()) ; 
        
        while(k > 0)
        {
            int x = pq.top() ; 
            pq.pop() ; 
            x = x - (x/2) ;
            pq.push(x) ; 
            
            k-- ; 
        }
        
        int sum = 0 ; 
        
        while(!pq.empty())
        {
            sum += pq.top() ; 
            pq.pop() ;
        }
        
        return sum ; 
    }
};