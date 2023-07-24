class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result ; 
        set<vector<int>> myset ; 
        sort(nums.begin() , nums.end()) ; 
        
        int n = nums.size() ; 
        
        for(int i=0 ; i<n-2 ; i++)
        {
            int x = nums[i] ; 
            int sum = 0 - x ; 
            int j=i+1 , k = n-1; 
            
            while(j < k)
            {
                if(nums[j] + nums[k] == sum)
                { 
                    // vector<int>
                    myset.insert({nums[i] , nums[j] , nums[k]}) ; 
                    j++ ; k-- ; 
                }
                else if(nums[j] + nums[k] < sum)
                {
                    j++ ; 
                }
                else
                    k-- ; 
            }
        }
        
        for (auto s : myset)
        {
            result.push_back(s) ; 
        }
        
        return result ; 
    }
};