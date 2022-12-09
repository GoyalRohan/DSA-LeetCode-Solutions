class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size() ; 
        unordered_map<int, int> mpp ; 
        
        for(auto ele : nums)
            mpp[ele]++ ; 
        
        for(auto m : mpp)
        {
            if(m.second > n/2)
                return m.first ; 
        }
        
        return 0 ; 
    }
};