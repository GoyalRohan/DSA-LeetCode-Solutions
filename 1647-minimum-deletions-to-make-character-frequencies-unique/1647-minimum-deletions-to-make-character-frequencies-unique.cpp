class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> mpp ; 
        
        for(auto str : s)
            mpp[str]++ ; 
        
        unordered_set<int> freq ; 
        int ans = 0 ; 
        
        for(auto m : mpp)
        {
            int x = m.second ; 
            if(freq.find(x) == freq.end())
                freq.insert(x) ; 
            else
            {
                while(x > 0 && freq.find(x) != freq.end())
                {
                    x = x-1 ; 
                    ans++ ; 
                }
                if(x < 0)
                    continue ; 
                freq.insert(x) ; 
            }
        }
        
        return ans ; 
    }
};