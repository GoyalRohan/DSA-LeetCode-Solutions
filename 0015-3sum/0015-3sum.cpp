class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result ; 
        // set<vector<int>> myset ; 
        sort(nums.begin() , nums.end()) ; 
        
        int n = nums.size() ; 
        
        for(int i=0 ; i<n-2 ; i++)
        {
            if(i > 0 && nums[i] == nums[i-1])
                continue ; 
            
            int x = nums[i] ; 
            int sum = 0 - x ; 
            int j=i+1 , k = n-1; 
            
            while(j < k)
            {
                int oldj= j , oldk = k ; 
                if(nums[j] + nums[k] == sum)
                { 
                    // vector<int>
                    result.push_back({nums[i] , nums[j] , nums[k]}) ; 
                    j++ ; k-- ; 
                    
                    while(j<k && nums[j] == nums[oldj])
                        j++ ; 
                    while(j<k && nums[k] == nums[oldk])
                        k-- ; 
                }
                else if(nums[j] + nums[k] < sum)
                {
                    j++ ; 
                }
                else
                    k-- ; 
            }
        }
        
        // for (auto s : myset)
        // {
        //     result.push_back(s) ; 
        // }
        
        return result ; 
    }
};