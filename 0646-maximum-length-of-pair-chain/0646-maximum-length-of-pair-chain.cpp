class Solution {
public:
    
    static bool compare(vector<int> &a , vector<int> &b)
    {
        return a[1] < b[1] ; 
    }
     
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size() ; 
        
        sort(pairs.begin() , pairs.end() , compare) ; 
        
        auto last = pairs[0] ; 
        
        int total = 1 ; 
        for(int i=1 ; i<n ; i++)
        {
            if(pairs[i][0] > last[1])
            {
                total++ ; 
                last = pairs[i] ; 
            }
        }
        
        return total ; 
    }
};