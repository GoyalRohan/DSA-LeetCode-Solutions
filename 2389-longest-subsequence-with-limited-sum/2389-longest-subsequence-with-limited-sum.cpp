class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size() ; 
        sort(nums.begin() , nums.end()) ; 
        
        vector<int> prefix(n , 0) ; 
        prefix[0] = nums[0] ; 
        
        for(int i=1 ; i<n ; i++)
            prefix[i] = nums[i]+ prefix[i-1] ; 
        
        vector<int> ans ; 
        for(int i=0 ; i<queries.size() ; i++)
        {
            ans.push_back(upper_bound(prefix.begin() , prefix.end() , queries[i]) - prefix.begin()) ; 
        }
        
        return ans ; 
    }
};