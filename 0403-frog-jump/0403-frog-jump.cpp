class Solution {
public:
    
    map<pair<int, int> , bool> dp ; 
    
    bool solve(int pos , int prevjump ,int n, vector<int>& stones, unordered_set<int> &myset)
    {
        // bool isPossible = false ; 
        
        if(pos > stones[n-1] || myset.find(pos) == myset.end())
            return false ; 
        
        if(pos == stones[n-1])
            return true ; 
        
        if(dp.find({pos, prevjump}) != dp.end())
            return dp[{pos, prevjump}] ; 
        
        for(int i=-1 ; i<=1 ; i++)
        {
            if(prevjump + i > 0)
            {
                if(solve(pos+prevjump+i , prevjump+i , n, stones, myset))
                    return dp[{pos+prevjump+i, prevjump+i}] = true ; 
            }
        }
        
        return dp[{pos, prevjump}] = false ; 
    }
    
    bool canCross(vector<int>& stones) {
        
        if(stones[1] - stones[0] > 1)
            return false ; 
        
        unordered_set<int> myset ; 
        int n = stones.size() ; 
        myset.insert(stones.begin(), stones.end()) ; 
        
        
        return solve(1 , 1 , n,  stones , myset) ; 
        
    }
};