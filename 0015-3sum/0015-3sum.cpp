class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<vector<int>, int > mpp ; 
        vector<vector<int >> ans ; 
        int n = nums.size() ;
        
        sort(nums.begin() , nums.end())  ;
        
        for(int i=0 ; i<n-2 ; i++)
        {
            int j=i+1 , k = n-1 ; 
            
            if(i > 0 && nums[i] == nums[i-1])
                continue ; 
            
            while(j < k)
            {
                int sum = nums[i] + nums[j] + nums[k] ; 
                
                if(sum == 0)
                {
                    vector<int> temp ; 
                    temp.push_back(nums[i]) ; 
                    temp.push_back(nums[j]) ; 
                    temp.push_back(nums[k]) ; 
                    
                    if(!mpp[temp])
                    {
                        ans.push_back(temp) ; 
                        mpp[temp] = 1 ; 
                    }
                    
                    int left = j , right = k  ; 
                    
                    while(j<k && nums[left] == nums[j])
                        j++ ; 
                    while(j<k && nums[right] == nums[k])
                        k-- ; 
                     
                }
                else if(sum > 0)
                    k-- ; 
                else
                    j++ ; 
            }
        }
        
        
        return ans ; 
    }
};