class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> mpp ; 
        
        for(auto n: nums)
            mpp[n] = true ; 
        
        for(auto n: nums)
        {
            if(mpp.find(n-1) != mpp.end())
                mpp[n] = false ; 
        }
        
        int maxlen = 0 ; 
        
        for(auto n: nums)
        {
            if(mpp[n] == true)
            {
                int curlen = 0 ; 
                int curele = n ; 
                
                while(mpp.find(curele) != mpp.end())
                {
                    curele++ ; 
                    curlen++ ; 
                }
                
                maxlen= max(maxlen , curlen) ; 
            }  
        }
        
        return maxlen ; 
       
    }
};