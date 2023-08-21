class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> mpp ;
        int cnt = 0 ; 
        
        for(auto n : nums)
        {
            if(mpp.find(n + k) != mpp.end())
                cnt += mpp[n+k] ; 
            
            if(mpp.find(n - k) != mpp.end())
                cnt += mpp[n-k] ;
            
            mpp[n]++ ; 
        }
        
        return cnt ; 
    }
};