class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int pairs=0;
        unordered_map<int , vector<int>> mpp ; 
        
        for(int i=0;i<nums.size() ;i++)
        {
            mpp[nums[i]].push_back(i) ; 
        }
        
        for(auto m : mpp)
        {
            auto vec = m.second  ;
            int n = vec.size() ; 
            if(n>1)
            {
                pairs += n*(n-1)/2 ; 
            }
        }
        
        return pairs;
    }
};