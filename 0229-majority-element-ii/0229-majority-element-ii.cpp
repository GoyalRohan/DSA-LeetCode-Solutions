class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        vector<int> ans ; 
        int n= nums.size() ; 
        unordered_map<int, int> mpp ; 
        
        for(int i=0 ; i<nums.size() ; i++)
        {
            mpp[nums[i]]++ ; 
        }
        
        for(auto m : mpp)
        {
            if(m.second > n/3)
                ans.push_back(m.first) ; 
        }
        
        return ans ; 
    }
};