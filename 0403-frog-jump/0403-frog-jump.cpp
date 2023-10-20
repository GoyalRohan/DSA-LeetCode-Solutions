class Solution {
public:
    
    map<pair<int, int> , bool> mpp ; 
    
    bool solve(int pos, int prevjump , int n, unordered_set<int> &s , vector<int>& stones)
    {
        if(pos > stones[n-1] || s.find(pos) == s.end())
            return false ; 
        
        if(pos == stones[n-1])
            return true ; 
        
        if(mpp.find({pos, prevjump}) != mpp.end())
            return mpp[{pos, prevjump}] ; 
        
        for(int jump=-1 ; jump<=1 ;jump++)
        {
            if(prevjump+jump > 0)
            {
                if(solve(pos+prevjump+jump , prevjump + jump , n , s , stones)) 
                    return  mpp[{pos, prevjump}] = true ; 
            }
        }
        
        return  mpp[{pos, prevjump}] = false ;
    }
    
    bool canCross(vector<int>& stones) {
        if(stones[1] - stones[0] > 1)
            return false ; 
        
        int n = stones.size() ; 
        
        unordered_set<int> s(stones.begin(), stones.end()) ; 
        
        return solve(1 , 1 , n, s , stones) ;
    }
};