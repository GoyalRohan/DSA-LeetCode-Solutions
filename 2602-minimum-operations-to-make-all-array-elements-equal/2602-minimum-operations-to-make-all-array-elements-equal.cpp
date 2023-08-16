class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        vector<long long> result ; 
        int n = nums.size() , m= queries.size() ; 
        sort(nums.begin(), nums.end()) ; 
        
        vector<long long> prefix(n+1 , 0) ; 
        
        for(int i=0 ; i<n ; i++)
            prefix[i+1] = prefix[i] + nums[i] ; 
        
        nums.insert(nums.begin(), 0) ; 
        n++ ; 
        
        
        for(auto q : queries)
        {
            
            
            long long lidx = (lower_bound(nums.begin(), nums.end() , q) - nums.begin()) - 1 ; 
            long long uidx = upper_bound(nums.begin(), nums.end() , q) - nums.begin() ; 
            // cout<<lidx<<" , "<<uidx<<endl ; 
            
            long long ans = q * lidx - (prefix[lidx] - prefix[0]) ; 
            if(uidx != n)
                ans +=  (prefix[n-1] - prefix[uidx-1]) - q*(n-uidx)  ; 
            
            result.push_back(ans) ; 
        }
        
        return result ; 
        
    }
};