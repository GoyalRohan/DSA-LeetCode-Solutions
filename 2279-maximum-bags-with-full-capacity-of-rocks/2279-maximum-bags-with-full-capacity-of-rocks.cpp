class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int k) {
        int n = capacity.size() ; 
        vector<int> count ; 
        
        for(int i=0 ; i<n ; i++)
            count.push_back(capacity[i] - rocks[i]) ; 
        
        sort(count.begin() , count.end()) ; 
        
        int i ; 
        for(i=0 ; i<n && k >= count[i] ; i++)
            k = k - count[i] ; 
        
        return i ; 
    }
};