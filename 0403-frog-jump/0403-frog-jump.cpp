class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size() ; 
        
        unordered_map<int, unordered_set<int>> mpp ; 
        
        mpp[stones[0]+1].insert(1) ; 
        
        for(int i=1 ; i<n ; i++)
        {
            int position = stones[i] ; 
            for(auto it : mpp[position])
            {
                mpp[position+it].insert(it) ; 
                mpp[position+it+1].insert(it+1) ; 
                mpp[position+it-1].insert(it-1) ; 
            }
        }
        
        return mpp[stones.back()].size() != 0 ; 
    }

};